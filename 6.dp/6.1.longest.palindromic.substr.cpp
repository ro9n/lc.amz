/**
 * @file 6.1.longest.palindromic.substr
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
  string longestPalindrome(string s) {
    if (s.empty()) return s;
    int n = s.size(), dp[n][n]; string best = s.substr(0, 1);
   
    if (n == 1) return best;

    for(int i = 0; i < n; ++i) dp[i][i] = 1;

    for(int l = 1; l < n; ++l) {
      for(int i = 0; i < n - l; ++i) {
        int j = i + l;
        dp[i][j] = s[i] == s[j] && (i + 1 > j - 1 ? 1 : dp[i + 1][j - 1]);
        if (dp[i][j] && j - i + 1 > best.size()) best = s.substr(i, j - i + 1);
      }
    }

    return best;
  }
};