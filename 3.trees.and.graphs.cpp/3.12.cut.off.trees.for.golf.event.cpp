/**
 * @file 3.12.cut.off.trees.for.golf.event
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday September 30 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define mp make_pair
#define all(k) k.begin(), k.end()
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

vvi visited;

int dis(ii u, ii v, vvi &f) {
  int n = f.size(), m = f[0].size();
  queue<iii> q; q.push({0, u});

  while (!q.empty()) {
    auto front = q.front(); q.pop();
    
    if (front.ss == v) return front.ff;

    for (int d = 0; d < 4; ++d) {
      int r = front.ss.ff + dr[d], c = front.ss.ss + dc[d];
      if (r < 0 || r >= n || c < 0 || c >= m || !f[r][c] || visited[r][c]) continue;
      visited[r][c] = 1; q.push({front.ff + 1, {r, c}});
    }
  }

  return -1;
}

class Solution {
 public:
  int cutOffTree(vector<vector<int>> &f) {
    int n = f.size(), m = f[0].size();

    vector<iii> trees;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (f[i][j] > 1) {
          trees.eb(mp(f[i][j], mp(i, j))); // h, (r, c)
        }
      }
    }

    sort(all(trees), [](iii a, iii b) { return a.ff < b.ff; });

    int d = 0; ii u = {0, 0};
    for(int i = 0; i < trees.size(); ++i) {
        ii v = trees[i].ss;
        visited.assign(n, vi(m, 0));
        int d1 = dis(u, v, f);
        if (d1 < 0) return d1;
        d += d1; f[v.ff][v.ss] = 1;
        u = v;
    }

    return d;
  }
};
