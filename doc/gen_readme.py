#!/usr/bin/env python3

from subprocess import Popen, PIPE
import os
import re
import json


curdir = os.path.abspath(os.path.curdir)
pardir = os.path.abspath(os.path.pardir)
page_root = 'https://github.com/oopsno/leetcode/blob/master/'


def list_cxx_in(d=pardir):
    files = Popen(['git', 'ls-files', '--full-name', d],
                  stdout=PIPE,
                  cwd=pardir,
                  universal_newlines=True).stdout.readlines()
    return filter(lambda x: x.endswith('.cpp'), map(str.strip, files))


def make_record(fn):
    def _make_record(elements):
        record = dict()
        for element in elements:
            record.update(fn(element))
        return record

    return _make_record


@make_record
def detect_uid(path):
    abspath = os.path.join(pardir, path)
    with open(abspath) as src:
        code = src.read()
        matches = re.findall('X(\d{1,3})', code)
    return [(uid, path) for uid in matches]


solutions = list_cxx_in('src/solution')
unittest = list_cxx_in('test')
solutions_map = detect_uid(solutions)
utests_map = detect_uid(unittest)
with open(os.path.join(curdir, 'leetcode.json')) as jf:
    uid_map = json.load(jf)


def format_lines(s, t, u):
    xs = []
    for uid, sol_src in solutions_map.items():
        fmt = '{} | [{}]({}) | [Solution]({}) | [Test]({})'
        us_src = utests_map.get(uid, 'README.md')
        quiz = uid_map[uid]
        line = (int(uid),
                fmt.format(uid, quiz['name'],
                           quiz['url'], page_root + sol_src, page_root + us_src))
        xs.append(line)
    fst = lambda x: x[0]
    snd = lambda x: x[1]
    xs.sort(key=fst)
    return map(snd, xs)


def to_markdown(xs):
    print('#leetcode',
          '',
          'ID | Quiz | Solution | Unit Test',
          '---|------|----------| --------- |', sep='\n')
    for x in xs:
        print(x)


xs = format_lines(solutions_map, utests_map, uid_map)
to_markdown(xs)

