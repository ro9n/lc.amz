/**
 * @file 4.3.word.search.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tue Jun 23 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> vvc;

int n, m;
const int x[] = {-1, 1, 0, 0}, y[] = {0, 0, -1, 1};
int v[200][200];

bool solve(vvc &g, const string &t, int i, int j, int ti) {
  // no match
  if (g[i][j] != t[ti]) return 0;
  // match: check i == n - 1
  else if (ti == t.size() - 1)
    return 1;
  // otherwise
  else {
    v[i][j] = 1;
    
    for (int k = 0; k < 4; ++k) {
      int di = i + x[k], dj = j + y[k];
      if (di < 0 || dj < 0 || di >= n || dj >= m)
        continue;
      else if (v[di][dj])
        continue;
      else if (solve(g, t, di, dj, ti + 1)) return 1;
    }

    v[i][j] = 0;
    return 0;
  }
}

class Solution {
 public:
  bool exist(vvc &g, string t) {
    if (g.empty() || g[0].empty()) return 0;

    n = g.size(), m = g[0].size();

    // clear
    memset(v, 0, sizeof v);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (solve(g, t, i, j, 0)) {
          return 1;
        }
      }
    }

    return 0;
  }
};