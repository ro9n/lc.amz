/**
 * @file 1.21.trapping.rain.water
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday September 19 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& h) {
    if (h.empty()) return 0;
    int n = h.size(), l[n], r[n], w = 0;

    l[0] = h[0], r[n - 1] = h[n - 1];
    for (int i = 1; i < n; ++i) l[i] = max(h[i], l[i - 1]);
    for (int i = n - 2; i >= 0; --i) r[i] = max(h[i], r[i + 1]);

    for (int i = 0; i < n; ++i) w += min(l[i], r[i]) - h[i];

    return w;
  }
};

//ro9n
class Solution {
 public:
  int trap(vector<int>& h) {
    int n = h.size(), ans = 0;

    for (int l = 0, r = n - 1, L = 0, R = n - 1; l < r;) {
      if (h[l] < h[r]) {
        ans += h[L] - h[l++];
        if (h[l] >= h[L]) L = l;
      } else if (h[l] > h[r]) {
        ans += h[R] - h[r--];
        if (h[r] >= h[R]) R = r;
      } else {
        ++l;
        if (h[l] >= h[L]) L = l;
      }
    }

    return ans;
  }
};
