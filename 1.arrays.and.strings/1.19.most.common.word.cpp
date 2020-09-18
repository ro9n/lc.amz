/**
 * @file 1.19.most.common.word
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
  string mostCommonWord(string p, vector<string>& b) {
    transform(p.begin(), p.end(), p.begin(), ::tolower);

    unordered_set<string> s(b.begin(), b.end());
    unordered_map<string, int> f;
    int l = 0, r = 0, n = p.size(), ff = 0;
    string best;

    while (r < n) {
      l = r;
      while (r < n && isalpha(p[r])) ++r;
      string ss = p.substr(l, r - l);
      if (!s.count(ss)) ++f[ss];
      while (r < n && !isalpha(p[r])) ++r;
    }

    for (auto it = f.begin(); it != f.end(); ++it) {
      if (it->second > ff) ff = it->second, best = it->first;
    }

    return best;
  }
};
