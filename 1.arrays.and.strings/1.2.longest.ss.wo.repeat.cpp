/**
 * @file 1.2.longest.ss.wo.repeat
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
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    unordered_map<int, int> m;
    int n = s.size(), best = 1, last = -1;

    for (int i = 0; i < n; ++i) {
      if (m.count(s[i])) last = max(last, m[s[i]]);
      m[s[i]] = i;
      best = max(best, i - last);
    }

    return best;
  }
};
