/**
 * @file 6.5.coin.change
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
  int coinChange(vector<int>& coins, int K) {
    vector<int> dp(K + 1, K + 1); dp[0] = 0;
    for (int k = 1; k <= K; ++k) {
      for (auto c : coins) {
        if (c <= k)
          dp[k] = min(dp[k], dp[k - c] + 1);
      }
    }

    return dp[K] == K + 1 ? -1 : dp[K];
  }
};
