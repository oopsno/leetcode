#include <fstream>
#include <iostream>
#include <regex>

#include <boost/filesystem.hpp>
#include <boost/format.hpp>

#include "leetcode.hpp"

namespace fs = boost::filesystem;

auto get_title_from(const fs::path &solution) {
  std::ifstream is{solution.string()};
  static char buffer[1024];
  std::regex title_pattern{R"(\s+\*\s+[0-9]*\.\s+(.*))"};
  is.getline(buffer, sizeof(buffer), '\n');
  is.getline(buffer, sizeof(buffer), '\n');
  const std::string line = buffer;
  std::match_results<std::string::const_iterator> match;
  auto matched = std::regex_match(line, match, title_pattern);
  if (not matched) {
    throw std::runtime_error{"Cannot guess the title of solution: " + solution.string()};
  }
  return match[1].str();
}

auto build_hyper_link(const LeetCode::SolutionDescriptor &descriptor, const fs::path &root) {
  std::stringstream ss;
  const auto href = fs::relative(descriptor.path, root).generic_string();
  ss << "[" << descriptor.title << "](" << href << ")";
  return ss.str();
}

int main(int argc, char *argv[]) {
  const auto src = fs::path{__FILE__}.parent_path();
  const auto root = src.parent_path();
  std::cout << "# LeetCode\n\n"
            << "|  ID  |                             Title                              |\n"
            << "|:-----|:---------------------------------------------------------------|\n";
  for (const auto &s : LeetCode::solution_manager.id_solution) {
    using boost::format;
    using boost::io::group;
    const auto serial = s.first;
    const auto &descriptor = s.second;
    const auto link = build_hyper_link(descriptor, root);
    std::cout << format("| %|-4d| | %|+62s| |") % serial % link << std::endl;
  }
  return 0;
}
