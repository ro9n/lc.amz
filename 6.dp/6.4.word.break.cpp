/**
 * @file 6.4.word.break
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 03 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& d) {
    /* 
    // bfs
    unordered_set<string> S(d.begin(), d.end());
    int n = s.size();
    queue<int> q; vector<int> v(n);
    q.push(0);

    while (!q.empty()) {
      int l = q.front(); q.pop();
      if (v[l]) continue;
      else v[l] = 1;
      for (int r = l; r < n; ++r) {
        if(S.count(s.substr(l, r - l + 1))) {
          if (r == n - 1) return 1;
          q.push(r + 1);
        }
      }
    }

    return 0;

    */

    // dp
    unordered_set<string> S(d.begin(), d.end());
    int n = s.size();
    vector<int> dp(n + 1, 0); dp[n] = 1;

    for(int i = n - 1; i >= 0; --i) {
      string k;
      for(int j = i; j < n && !dp[i]; ++j) {
        k += s[j];
        dp[i] |= dp[j + 1] && S.count(k);
      }
    }
    
    return dp[0];
  }
};

int main() {
  auto s = new Solution();
  vector<string> v{"leet", "code"};
  s->wordBreak("leetcode", v);
  return 0;
}