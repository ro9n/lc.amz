/**
 * @file 5.7.top.k.frequest.elements
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
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> f;
    priority_queue<pair<int, int>> q;
    vector<int> ans;

    for (auto x : nums) ++f[x];
    
    for (auto x : f) {
      q.push({x.second, x.first});
    }
    
    while (k--) ans.emplace_back(q.top().second), q.pop();
    return ans;
  }
};
