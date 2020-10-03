/**
 * @file 6.3.best.time.to.buy.and.sell.stock
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 03 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

class Solution {
public:
    int maxProfit(vector<int>& p) {
        if(p.empty()) return 0;
        int best = 0, mn = INF;
        
        for(auto k: p) {
          mn = min(mn, k);
          best = max(best, k - mn);
        }

        return best;
    }
};