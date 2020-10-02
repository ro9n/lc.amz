/**
 * @file 5.5.kth.largest
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 03 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

// O(n lg k)
// quickselect has best case linear O(n) and worst case quadratic O(n²)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;

        for(auto x: nums) {
          q.push(-x);
          while (q.size() > k) q.pop();
        }

        return -q.top();
    }
};