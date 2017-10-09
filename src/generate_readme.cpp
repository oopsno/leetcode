#include <fstream>
#include <iostream>
#include <regex>
#include <map>

#include <boost/filesystem.hpp>
#include <boost/format.hpp>

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

auto find_solutions(const fs::path &src) {
  std::map<int, fs::path> solutions;
  const std::regex pattern {"([0-9]+)\\.cpp"};
  std::match_results<std::string::const_iterator> match;
  for (const auto &entry : fs::directory_iterator{src}) {
    const auto &path = entry.path();
    const auto filename = path.filename().string();
    if (std::regex_match(filename, match, pattern)) {
      auto serial_string = match[1].str();
      char *parse_end;
      const auto serial = std::strtol(serial_string.c_str(), &parse_end, 10);
      solutions[serial] = path;
    };
  }
  return solutions;
};

auto build_hyper_link(int serial, const fs::path& solution, const fs::path& root) {
  std::stringstream ss;
  const auto title = get_title_from(solution);
  const auto href = fs::relative(solution, root).generic_string();
  ss << "[" << title << "](" << href << ")";
  return ss.str();
}

int main(int argc, char *argv[]) {
  const auto src = fs::path{__FILE__}.parent_path();
  const auto root = src.parent_path();
  auto solutions = find_solutions(src);
  std::cout << "# LeetCode\n\n"
            << "|  ID  |                             Title                              |\n"
            << "|:-----|:---------------------------------------------------------------|\n";
  for (const auto& [serial, solution] : solutions) {
    using boost::format;
    using boost::io::group;
    const auto link = build_hyper_link(serial, solution, root);
    std::cout << format("| %|-4d| | %|+62s| |") % serial % link << std::endl;
  }
  return 0;
}
