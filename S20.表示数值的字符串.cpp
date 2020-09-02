#include <cstring>
#include <string>

enum State {
  START, // 初始状态
  LEADING_SPACE,
  SIGN,
  INTEGRAL,
  DANGLING_POINT,
  POINT,
  FRACTIONAL,
  E,
  EXP_SIGN,
  EXP_DIGITS,
  TAILING_SPACE,
  ERROR
};

class Solution {
private:
  State on_start(const char next) const noexcept {
    if (std::isspace(next)) {
      return State::LEADING_SPACE;
    } else if (std::isdigit(next)) {
      return State::INTEGRAL;
    } else if (next == '+' or next == '-') {
      return State::SIGN;
    } else if (next == '.') {
      return State::DANGLING_POINT;
    } else {
      return State::ERROR;
    }
  }

  State on_leading_space(const char next) const noexcept {
    if (std::isspace(next)) {
      return State::LEADING_SPACE;
    } else {
      return on_start(next);
    }
  }

  State on_sign(const char next) const noexcept {
    if (std::isdigit(next)) {
      return State::INTEGRAL;
    } else if (next == '.') {
      return State::DANGLING_POINT;
    } else {
      return State::ERROR;
    }
  }

  State on_integral(const char next) const noexcept {
    if (std::isdigit(next)) {
      return State::INTEGRAL;
    } else if (std::isspace(next)) {
      return State::TAILING_SPACE;
    } else if (next == 'E' or next == 'e') {
      return State::E;
    } else if (next == '.') {
      return State::POINT;
    } else {
      return State::ERROR;
    }
  }

  State on_dangling_point(const char next) const noexcept {
    if (std::isdigit(next)) {
      return State::FRACTIONAL;
    } else {
      return State::ERROR;
    }
  }

  State on_point(const char next) const noexcept {
    if (std::isspace(next)) {
      return State::TAILING_SPACE;
    } else if (next == 'E' or next == 'e') {
      return State::E;
    } else {
      return on_dangling_point(next);
    }
  }

  State on_fractional(const char next) const noexcept {
    if (std::isdigit(next)) {
      return State::FRACTIONAL;
    } else if (std::isspace(next)) {
      return State::TAILING_SPACE;
    } else if (next == 'E' or next == 'e') {
      return State::E;
    } else {
      return State::ERROR;
    }
  }

  State on_e(const char next) const noexcept {
    if (std::isdigit(next)) {
      return State::EXP_DIGITS;
    } else if (next == '+' or next == '-') {
      return State::EXP_SIGN;
    } else {
      return State::ERROR;
    }
  }
  State on_exp_sign(const char next) const noexcept {
    if (std::isdigit(next)) {
      return State::EXP_DIGITS;
    } else {
      return State::ERROR;
    }
  }

  State on_exp_dights(const char next) const noexcept {
    if (std::isspace(next)) {
      return State::TAILING_SPACE;
    } else if (std::isdigit(next)) {
      return State::EXP_DIGITS;
    } else if (std::isspace(next)) {
      return State::TAILING_SPACE;
    } else {
      return State::ERROR;
    }
  }

  State on_tailing_space(const char next) const noexcept {
    if (std::isspace(next)) {
      return State::TAILING_SPACE;
    } else {
      return State::ERROR;
    }
  }

  State transfer(State current, char next) const noexcept {
    switch (current) {
    case State::START:
      return on_start(next);
    case State::LEADING_SPACE:
      return on_leading_space(next);
    case State::SIGN:
      return on_sign(next);
    case State::INTEGRAL:
      return on_integral(next);
    case State::DANGLING_POINT:
      return on_dangling_point(next);
    case State::POINT:
      return on_point(next);
    case State::FRACTIONAL:
      return on_fractional(next);
    case State::E:
      return on_e(next);
    case State::EXP_SIGN:
      return on_exp_sign(next);
    case State::EXP_DIGITS:
      return on_exp_dights(next);
    case State::TAILING_SPACE:
      return on_tailing_space(next);
    default:
      return State::ERROR;
    }
  }

  bool acceptable(State state) const noexcept {
    switch (state) {
    case State::INTEGRAL:
    case State::POINT:
    case State::FRACTIONAL:
    case State::EXP_DIGITS:
    case State::TAILING_SPACE:
      return true;

    default:
      return false;
    }
  }

public:
  bool isNumber(const std::string s) const noexcept {
    State state = State::START;
    for (char c : s) {
      state = transfer(state, c);
      if (state == State::ERROR) {
        break;
      }
    }
    return acceptable(state);
  }
};

#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> yes{"+100",   "5e2",  "-123", "3.1416",
                               "-1E-16", "0123", "3. ",  "46.e3"};
  std::vector<std::string> no{"12e",     "1a3.14", "1.2.3", "+-5",
                              "12e+5.4", " -.",    "-.e42"};
  Solution s;
  for (const std::string &literal : yes) {
    std::cout << "YES: " << std::boolalpha << s.isNumber(literal) << std::endl;
  }
  for (const std::string &literal : no) {
    std::cout << "NO:  " << std::boolalpha << s.isNumber(literal) << std::endl;
  }
  return 0;
}