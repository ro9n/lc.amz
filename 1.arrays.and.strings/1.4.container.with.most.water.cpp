/**
 * @file 1.4.container.with.most.water
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday September 17 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& h) {
    int n = h.size(), best = 0;
    
    for(int l = 0, r = n - 1; l < r;) {
        best = max(best, min(h[l], h[r]) * (r - l));
        if (h[l] > h[r]) --r;
        else ++l;
    }
    
    return best;
  }
};