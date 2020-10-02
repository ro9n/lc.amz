/**
 * @file 5.1.median.of.two.sorted.arrays
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 02 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if (a.size() > b.size()) swap(a, b);
    int n = a.size(), m = b.size();

    int l = 0, r = n; while(l <= r) {
      int i = l + ceil((r - l) / 2.f), j = (n + m) / 2 - i; // pivot on a, b
      // ith element is on the right of the segment
      int mx = max(i > 0 ? a[i - 1] : -INF, j > 0 ? b[j - 1]: -INF); // max from left segment
      int mn = min(i < n ? a[i] : INF, j < m ? b[j] : INF); // min from right segment

      if (mx <= mn) return ((n + m) & 1) ? mn : (mx + mn) / 2.f;
      else if (i < n && a[i] == mn) l = i + 1;
      else r = i - 1;
    }

    return 0;
  }
};

