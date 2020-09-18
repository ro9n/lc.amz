/**
 * @file 1.12.min.window.substr
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday September 18 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

class Solution {
 public:
  string minWindow(string t, string p) {
    int k = p.size(), n = t.size();
    unordered_map<int, int> f;
    pair<int, int> best = {-1, n};
    for (auto c : p) ++f[c];

    for (int l = 0, r = 0, c = 0; r < n; ++r) {
      if (--f[t[r]] >= 0) ++c;  // a required character
      while (c == k) {
        if (best.ss - best.ff > r - l)
          best = {l, r};  // consider the current interval
        // shrink
        if (++f[t[l]] > 0) --c;  // discard: > 0 required character
        ++l;
      }
    }

    if (best.ss - best.ff + 1 > n) return "";
    else return t.substr(best.ff, best.ss - best.ff + 1);
  }
};