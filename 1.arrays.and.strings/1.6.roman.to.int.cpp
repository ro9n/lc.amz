/**
 * @file 1.6.roman.to.int
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday September 18 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> m{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                               {'C', 100}, {'D', 500}, {'M', 1000}};

    int n = s.size(), k = 0;
    for (int i = 0; i < n; ++i) {
        int k2 = m[s[i]];
        if (i + 1 < n && m[s[i + 1]] > k2) k2 = m[s[i + 1]] - k2, ++i;
        k += k2;
    }

    return k;
  }
};