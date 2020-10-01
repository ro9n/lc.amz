/**
 * @file 3.7.word.ladder
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday September 21 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

class Solution {
public:
    int ladderLength(string b, string e, vector<string>& d) {
      unordered_set<string> S(d.begin(), d.end());

      queue<pair<string, int>> q;
      q.push({b, 0});

      while(!q.empty()) {
        auto f = q.front(); q.pop();
        string s = f.ff; int l = f.ss, n = s.size();
        if (s == e) return l;
        
        for(int i = 0; i < n; ++i) {
          int c = s[i];
          for(int j = 'a'; j <= 'z'; ++j) {
            s[i] = j;
            if (S.count(s)) S.erase(s), q.push({s, l + 1});
          }
          s[i] = c;
        }
      }

      return 0;        
    }
};
