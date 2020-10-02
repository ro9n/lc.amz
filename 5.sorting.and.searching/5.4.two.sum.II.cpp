/**
 * @file 5.4.two.sum.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 02 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int k) {
    for (int i = 0, n = numbers.size(); i < n; ++i) {
      vector<int>::iterator it =
          lower_bound(numbers.begin() + i + 1, numbers.end(), k - numbers[i]);
      if (*it == k - numbers[i])
        return {i + 1, (int)(it - numbers.begin()) + 1};
    }

    return {};
  }
};
