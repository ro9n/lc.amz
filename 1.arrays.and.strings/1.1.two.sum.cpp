/**
 * @file 1.1.two.sum
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
  vector<int> twoSum(vector<int>& v, int k) {
    int n = v.size();
    unordered_map<int, int> m;

    for (int i = 0; i < n; ++i) {
      if (m.find(k - v[i]) != m.end()) return {m[k - v[i]], i};
      else m[v[i]] = i;
    }

    return {};
  }
};
