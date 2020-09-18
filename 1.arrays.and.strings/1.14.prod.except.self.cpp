/**
 * @file 1.14.prod.except.self
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday September 18 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& v) {
    int n = v.size(); vector<int> r(n, 1);
    
    for(int i = 0, pfx = 1; i < n; ++i) {
        r[i] *= pfx;
        pfx *= v[i];
    }

    for(int i = n - 1, sfx = 1; i >= 0; --i) {
        r[i] *= sfx;
        sfx *= v[i];
    }

    return r;
  }
};

