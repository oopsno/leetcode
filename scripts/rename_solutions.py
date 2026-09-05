#!/usr/bin/env python3
"""Rename solution files to match AGENTS.md convention: NNNN-slug.cpp"""

from __future__ import annotations

import re
import subprocess
import sys
from pathlib import Path
from typing import Optional

SOLUTIONS_DIR = Path(__file__).parent.parent / "solutions"

def get_problem_slug(problem_id: int) -> Optional[str]:
    """Fetch problem slug from leetcode-local-cli."""
    try:
        result = subprocess.run(
            ["uv", "tool", "run", "--from", "leetcode-local-cli", "lc", "get", str(problem_id)],
            capture_output=True, text=True, timeout=30
        )
        if result.returncode != 0:
            return None
        
        # Parse output to find slug
        # Output format includes: │ Slug        two-sum │
        for line in result.stdout.split('\n'):
            match = re.search(r'Slug\s+(\S+)', line)
            if match:
                return match.group(1)
        return None
    except Exception as e:
        print(f"Error fetching slug for problem {problem_id}: {e}", file=sys.stderr)
        return None

def extract_problem_id(filename: str) -> Optional[int]:
    """Extract problem ID from filename."""
    # Match patterns like: 0001, 0053, 102, 918, etc.
    match = re.match(r'^(\d+)[.\-]', filename)
    if match:
        return int(match.group(1))
    return None

def needs_rename(filename: str) -> bool:
    """Check if filename needs renaming to match convention."""
    # Convention: NNNN-slug.cpp (4-digit zero-padded, hyphen separator)
    return not re.match(r'^\d{4}-[a-z0-9\-]+\.cpp$', filename)

def main():
    # Find files that need renaming
    files_to_rename = []
    for f in sorted(SOLUTIONS_DIR.glob("*.cpp")):
        if needs_rename(f.name):
            problem_id = extract_problem_id(f.name)
            if problem_id is not None:
                files_to_rename.append((f, problem_id))
    
    if not files_to_rename:
        print("All files already follow the naming convention.")
        return
    
    print(f"Found {len(files_to_rename)} files to rename.")
    
    # Fetch slugs
    slug_cache = {}
    for _, problem_id in files_to_rename:
        if problem_id not in slug_cache:
            slug = get_problem_slug(problem_id)
            if slug:
                slug_cache[problem_id] = slug
    
    # Rename files
    renamed = 0
    for filepath, problem_id in files_to_rename:
        slug = slug_cache.get(problem_id)
        if not slug:
            print(f"Warning: Could not find slug for problem {problem_id} ({filepath.name})")
            continue
        
        # Create new filename
        new_name = f"{problem_id:04d}-{slug}.cpp"
        new_path = filepath.parent / new_name
        
        if new_path.exists():
            print(f"Warning: Target file already exists: {new_name}")
            continue
        
        print(f"Renaming: {filepath.name} -> {new_name}")
        filepath.rename(new_path)
        renamed += 1
    
    print(f"\nRenamed {renamed} files.")

if __name__ == "__main__":
    main()
