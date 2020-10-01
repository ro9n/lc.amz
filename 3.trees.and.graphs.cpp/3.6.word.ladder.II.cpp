/**
 * @file 3.6.word.ladder.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday September 21 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define all(k) k.begin(), k.end()

int p = 0;
vector<vector<string>> ans(100, vector<string>());
unordered_map<string, unordered_set<string>> g;

bool dfs(const string& u, const string& parent, const string& k) {
  if (u == k) {
    ans[p++].eb(u); return 1;
  }

  for(auto v: g[u]) {
    if (v == parent) continue;
    if (dfs(v, u, k)) ans[p].eb(v);
  }
}

class Solution {
public:
    vector<vector<string>> findLadders(string b, string e, vector<string>& d) {
        d.eb(b), d.eb(e);
        unordered_set<string> s(all(d));
        ans.clear();
        p = 0;
        g.clear();

        for(auto w: d) {
          string w1 = w;
          for(auto i = 0; i < w.size(); ++i) {
            auto c = w[i];
            for(auto j = 'a'; j <= 'z'; ++j) {
              if (j == c) continue;
              w[i] = j;
              if(s.count(w)) g[w].insert(w1), g[w1].insert(w);
            }
          }
        }

        dfs(b, 0, e);

        ans.resize(p);
        int mn = INT_MAX;
        for(int i = 0; i < ans.size(); ++i) {
          reverse(all(ans[i]));
          mn = min(mn, (int) ans[i].size());
        }

        return ans;
    }
};