/**
 * @file 4.3.word.search.revisited
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 02 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int visited[200][200];

// 3ᵏ
// we could have at most 4 directions to explore, but further the choices are
// reduced into 3 (since we won't go back to where we come from)
bool dfs(int i, int j, const vector<vector<char>> &b, const string &k, int ki) {
  int n = b.size(), m = b[0].size(), ans = 0;

  if (ki == k.size()) return 1;

  visited[i][j] = 1;

  for (int d = 0; d < 4; ++d) {
    int r = i + dr[d], c = j + dc[d];
    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || k[ki] != b[r][c])
      continue;
    if (dfs(r, c, b, k, 1 + ki)) return 1;
  }

  visited[i][j] = 0;
  return 0;
}

// Nx3ᵏ
class Solution {
 public:
  bool exist(vector<vector<char>> &b, string k) {
    int n = b.size(), m = b[0].size();
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (k[0] == b[i][j])
          if (dfs(i, j, b, k, 1)) return 1;
      }
    }
    return 0;
  }
};
