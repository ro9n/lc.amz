/**
 * @file 3.6.word.ladder.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday January 16 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<string>> findLadders(string b, string e, vector<string>& d) {
    unordered_set<string> s(d.begin(), d.end());
    s.insert(b);
    if (!s.count(e)) return {};

    unordered_map<string, vector<string>> adj;

    for (auto u : s) {
      for (int j = 0, m = u.size(); j < m; ++j) {
        string v = u;
        int c = u[j];
        for (int k = 0; k < 26; ++k) {
          if (k + 97 == c) continue;
          v[j] = k + 97;
          if (s.count(v)) adj[u].push_back(v);
        }
        v[j] = c;
      }
    }

    unordered_set<string> visited;
    queue<vector<string>> q;
    q.push({b});
    visited.insert(b);
    vector<vector<string>> ans;
    int best = 1e9 + 7;

    while (!q.empty()) {
      auto f = q.front();
      q.pop();

      if (f.size() > best) continue;

      if (f.back() == e) {
        best = (int)f.size();

        ans.push_back(f);
      }

      visited.insert(f.back());

      for (auto v : adj[f.back()]) {
        if (!visited.count(v) || v == e) {
          auto tmp = f;
          tmp.push_back(v);
          q.push(tmp);
        }
      }
    }

    return ans;
  }
};