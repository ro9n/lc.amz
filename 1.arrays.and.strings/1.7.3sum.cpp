/**
 * @file 1.7.3sum
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
  vector<vector<int>> threeSum(vector<int>& v) {
    if (v.empty()) return {};
    vector<vector<int>> R;

    int n = v.size();
    sort(v.begin(), v.end());

    for (int i = 0; i < n && v[i] <= 0; ++i) {
      if (i > 0 && v[i - 1] == v[i]) continue;
      for (int l = i + 1, r = n - 1; l < r;) {
        int s = v[i] + v[l] + v[r];
        if (s > 0)
          --r;
        else if (s < 0)
          ++l;
        else {
          R.emplace_back(vector<int>{v[i], v[l++], v[r--]});
          while (l < r && v[l - 1] == v[l]) ++l;
        }
      }
    }

    return R;
  }
};