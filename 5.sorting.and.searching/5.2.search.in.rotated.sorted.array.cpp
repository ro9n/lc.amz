/**
 * @file 5.2.search.in.rotated.sorted.array
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
  int search(vector<int>& a, int k) {
    int n = a.size();

    int l = 0, r = n - 1; while (l <= r) {
      int m = l + ((r - l) >> 1);
      if (a[m] == k) return m;
      else if (a[l] <= a[m]) {
        if (a[l] <= k && k < a[m]) r = m - 1;
        else l = m + 1;
      } else {
        if (a[m] < k && k <= a[r]) l = m + 1;
        else r = m - 1;
      }
    }
    return -1;
  }
};