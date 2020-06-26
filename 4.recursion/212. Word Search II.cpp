/**
 * @file 4.4.Word Search II.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu Jun 25 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class trie {
 public:
  trie *next[26];
  bool leaf;
  trie() {
    leaf = 0;
    for (int i = 0; i < 26; ++i) {
      next[i] = 0;
    }
  }

  void insert(string w) {
    trie *r = this;
    for (auto c : w) {
      if (!r->next[c - 'a']) r->next[c - 'a'] = new trie();
      r = r->next[c - 'a'];
    }
    r->leaf = 1;
  }
};

unordered_set<string> match;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool vis[200][200];
int n, m;

class Solution {
  void find(vector<vector<char>> &g, int i, int j, trie *r, string s) {
    int c = g[i][j] - 'a';
    if (!r->next[c])
      return;
    else if (r->next[c]->leaf) {
      match.insert(s + g[i][j]);
    }
    vis[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
      int di = i + dx[k], dj = j + dy[k];
      if (di < 0 || dj < 0 || di >= n || dj >= m)
        continue;
      else if (vis[di][dj])
        continue;
      else {
        find(g, di, dj, r->next[c], s + g[i][j]);
      }
    }
    vis[i][j] = 0;
  }

 public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    trie *r = new trie();
    match.clear();
    memset(vis, 0, sizeof vis);
    for (auto w : words) {
      r->insert(w);
    }

    n = board.size(), m = board[0].size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        find(board, i, j, r, "");
      }
    }

    return vector<string>(match.begin(), match.end());
  }
};