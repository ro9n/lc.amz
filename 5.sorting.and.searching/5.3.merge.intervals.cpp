/**
 * @file 5.3.merge.intervals
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 03 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

inline bool overlap(vector<int> x, vector<int> y) {
  // assumes y is greater
  return x[0] <= y[0] && x[1] >= y[0];
}

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());

    for (auto v : intervals) {
      if (ans.empty()) ans.push_back(v);
      else {
        auto u = ans.back();
        if (overlap(u, v)) ans.pop_back(), ans.emplace_back(vector<int>{min(u[0], v[0]), max(u[1], v[1])});
        else ans.emplace_back(v);
      }
    }

    return ans;
  }
};
