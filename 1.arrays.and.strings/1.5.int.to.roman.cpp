/**
 * @file 1.5.int.to.roman
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday September 17 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string intToRoman(int k) {
    // 9, 5, 4, 1
    vector<int> d = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> c = {"M", "CM", "D", "CD", "C", "XC", "L",
                        "XL", "X", "IX", "V", "IV", "I"};
    string s;
    for (int i = 0; k && i < c.size(); ++i)
      while (d[i] <= k) k -= d[i], s += c[i];
    return s;
  }
};

map<int, string> m{
    {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

class Solution {
 public:
  string intToRoman(int num) {
    string ans = "";
    while (num > 0) {
      for (auto it = m.rbegin(); it != m.rend(); ++it) {
        if (num >= it->first) {
          num -= it->first, ans += it->second;
          break;
        }
      }
    }

    return ans;
  }
};