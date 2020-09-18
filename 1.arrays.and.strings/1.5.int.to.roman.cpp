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
    vector<string> c = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                        "XL", "X",  "IX", "V",  "IV", "I"};
    string s;
    for (int i = 0; k && i < c.size(); ++i)
      while (d[i] <= k) k -= d[i], s += c[i];
    return s;
  }
};
