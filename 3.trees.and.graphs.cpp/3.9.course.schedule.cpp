/**
 * @file 3.9.course.schedule
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday September 29 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

vector<vector<int>> g;
vector<bool> vis;
vector<int> memo;

bool dfs(int u) {
  if (vis[u])
    return 0;
  else if (~memo[u])
    return memo[u];
  vis[u] = 1;
  for (auto v : g[u]) {
    if (!dfs(v)) return memo[u] = 0;
  }

  vis[u] = 0;
  return memo[u] = 1;
}

class Solution {
 public:
  bool canFinish(int k, vector<vector<int>>& pre) {
    if (pre.empty()) return 1;
    vis.assign(k, 0);
    g.assign(k, vector<int>());
    memo.assign(k, -1);
    for (auto p : pre) {
      g[p[1]].eb(p[0]);
    }

    for (int i = 0; i < g.size(); ++i) {
      if (!dfs(i)) return 0;
    }
    return 1;
  }
};