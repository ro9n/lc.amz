/**
 * @file 1.15.missing.num
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
  int missingNumber(vector<int>& v) {
    int n = v.size();
    unordered_set<int> s(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
      if (!s.count(i)) return i;

    return n;
  }
  
  int missingNumber(vector<int>& v) {
    int n = v.size(), k = n;
    // We can harness the fact that XOR is its own inverse to find the missing
    // element in linear time.
    for (int i = 0; i < n; ++i) k ^= i ^ v[i];

    return k;
  }
};
