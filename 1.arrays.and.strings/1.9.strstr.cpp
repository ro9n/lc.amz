/**
 * @file 1.9.strstr
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
  int strStr(string t, string p) {
    if (p.empty() && t.empty()) return 0;
    string s = p + '$' + t;
    int n = s.size();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
      if (i <= r) z[i] = min(r - i + 1, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
      if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }

    for (int i = p.size() + 1; i < n; ++i) {
      if (z[i] == p.size()) return i - (p.size() + 1);
    }

    return -1;
  }
};

