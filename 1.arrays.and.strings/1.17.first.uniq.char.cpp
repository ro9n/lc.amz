/**
 * @file 1.17.first.uniq.char
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday September 19 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_map<int, int> m;

    for (auto c : s) ++m[c - 'a'];
    for (int i = 0; i < s.size(); ++i)
      if (m[s[i] - 'a'] == 1) return i;

    return -1;
  }
};
