#include <gtest/gtest.h>
#include "solution/IntegerToRoman.cpp"

namespace X12 {

Solution s;

typedef std::pair<int, std::string> case_t;

TEST(IntegerToRoman, Utilities) {
  EXPECT_EQ(std::strcmp(TABLE[0][3].data(), "III"), 0);
  EXPECT_EQ(std::strcmp(TABLE[0][4].data(), "IV"), 0);
  EXPECT_EQ(std::strcmp(TABLE[0][5].data(), "V"), 0);
  EXPECT_EQ(std::strcmp(TABLE[0][6].data(), "VI"), 0);
}

TEST(IntegerToRoman, Hundred) {
  std::vector<case_t> cases = {
      case_t{1, "I"},
      case_t{21, "XXI"},
      case_t{41, "XLI"},
      case_t{61, "LXI"},
      case_t{81, "LXXXI"},
      case_t{2, "II"},
      case_t{22, "XXII"},
      case_t{42, "XLII"},
      case_t{62, "LXII"},
      case_t{82, "LXXXII"},
      case_t{3, "III"},
      case_t{23, "XXIII"},
      case_t{43, "XLIII"},
      case_t{63, "LXIII"},
      case_t{83, "LXXXIII"},
      case_t{4, "IV"},
      case_t{24, "XXIV"},
      case_t{44, "XLIV"},
      case_t{64, "LXIV"},
      case_t{84, "LXXXIV"},
      case_t{5, "V"},
      case_t{25, "XXV"},
      case_t{45, "XLV"},
      case_t{65, "LXV"},
      case_t{85, "LXXXV"},
      case_t{6, "VI"},
      case_t{26, "XXVI"},
      case_t{46, "XLVI"},
      case_t{66, "LXVI"},
      case_t{86, "LXXXVI"},
      case_t{7, "VII"},
      case_t{27, "XXVII"},
      case_t{47, "XLVII"},
      case_t{67, "LXVII"},
      case_t{87, "LXXXVII"},
      case_t{8, "VIII"},
      case_t{28, "XXVIII"},
      case_t{48, "XLVIII"},
      case_t{68, "LXVIII"},
      case_t{88, "LXXXVIII"},
      case_t{9, "IX"},
      case_t{29, "XXIX"},
      case_t{49, "XLIX"},
      case_t{69, "LXIX"},
      case_t{89, "LXXXIX"},
      case_t{10, "X"},
      case_t{30, "XXX"},
      case_t{50, "L"},
      case_t{70, "LXX"},
      case_t{90, "XC"},
      case_t{11, "XI"},
      case_t{31, "XXXI"},
      case_t{51, "LI"},
      case_t{71, "LXXI"},
      case_t{91, "XCI"},
      case_t{12, "XII"},
      case_t{32, "XXXII"},
      case_t{52, "LII"},
      case_t{72, "LXXII"},
      case_t{92, "XCII"},
      case_t{13, "XIII"},
      case_t{33, "XXXIII"},
      case_t{53, "LIII"},
      case_t{73, "LXXIII"},
      case_t{93, "XCIII"},
      case_t{14, "XIV"},
      case_t{34, "XXXIV"},
      case_t{54, "LIV"},
      case_t{74, "LXXIV"},
      case_t{94, "XCIV"},
      case_t{15, "XV"},
      case_t{35, "XXXV"},
      case_t{55, "LV"},
      case_t{75, "LXXV"},
      case_t{95, "XCV"},
      case_t{16, "XVI"},
      case_t{36, "XXXVI"},
      case_t{56, "LVI"},
      case_t{76, "LXXVI"},
      case_t{96, "XCVI"},
      case_t{17, "XVII"},
      case_t{37, "XXXVII"},
      case_t{57, "LVII"},
      case_t{77, "LXXVII"},
      case_t{97, "XCVII"},
      case_t{18, "XVIII"},
      case_t{38, "XXXVIII"},
      case_t{58, "LVIII"},
      case_t{78, "LXXVIII"},
      case_t{98, "XCVIII"},
      case_t{19, "XIX"},
      case_t{39, "XXXIX"},
      case_t{59, "LIX"},
      case_t{79, "LXXIX"},
      case_t{99, "XCIX"},
      case_t{20, "XX"},
      case_t{40, "XL"},
      case_t{60, "LX"},
      case_t{80, "LXXX"},
      case_t{100, "C"},
  };
  for (case_t c : cases) {
    EXPECT_EQ(s.intToRoman(c.first), c.second);
  }
}

}

