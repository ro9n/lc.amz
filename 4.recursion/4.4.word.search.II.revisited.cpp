/**
 * @file 4.4.word.search.II.revisited
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 02 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class trie {
 public:
  bool leaf;
  trie* next[26];

  void insert(string w);
};

void trie::insert(string w) {
  auto h = this;
  for (auto c : w) {
    if (!h->next[c - 'a']) h->next[c - 'a'] = new trie();
    h = h->next[c - 'a'];
  }
  h->leaf = 1;
}

const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int visited[200][200];
unordered_set<string> ans;

class Solution {
  void dfs(trie* h, vector<vector<char>>& b, int i, int j, const string& s) {
    if(h->leaf) ans.insert(s);
    visited[i][j] = 1;

    for(int d = 0; d < 4; ++d) {
      int r = i + dr[d], c = j + dc[d];
      if(r < 0 || r >= b.size() || c < 0 || c >= b[0].size() || visited[r][c] || !h->next[b[r][c] - 'a']) continue;
      dfs(h->next[b[r][c] - 'a'], b, r, c, s + b[r][c]);
    }

    visited[i][j] = 0;
  }

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (words.empty()) return {};

    trie* r = new trie(); for (auto w : words) {
      r->insert(w);
    }

    int n = board.size(), m = board[0].size();
    memset(visited, 0, sizeof visited);
    ans.clear();

    // O(M x 3ᴸ) 
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!r->next[board[i][j] - 'a']) continue;
        // i, j matches, expand
        dfs(r->next[board[i][j] - 'a'], board, i, j, string(1, board[i][j]));
      }
    }

    return vector<string>(ans.begin(), ans.end());
  }
};
