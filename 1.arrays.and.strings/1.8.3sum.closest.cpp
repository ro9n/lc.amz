/**
 * @file 1.8.3sum.closest
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday September 18 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 2001;

class Solution {
 public:
  int threeSumClosest(vector<int>& v, int k) {
    int n = v.size(), d = INF, S = 0;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
      for (int l = i + 1, r = n - 1; l < r;) {
        int s = v[i] + v[l] + v[r];
        if (d > abs(k - s)) d = abs(k - s), S = s;
        if (s < k) ++l; else --r;
      }
    }

    return S;
  }
};
