/**
 * @file 6.2.max.subarray
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
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size(), best = nums[0];
    for (int i = 1; i < n; ++i) {
      if(nums[i - 1] > 0) nums[i] += nums[i - 1];
      best = max(best, nums[i]);
    }

    return best;
  }
};
