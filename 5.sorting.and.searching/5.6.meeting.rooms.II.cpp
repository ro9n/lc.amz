/**
 * @file 5.6.meeting.rooms.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 03 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

class Solution {
 public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    priority_queue<int> q;
    q.push(-1);

    for (auto k : intervals) {
      if (-q.top() <= k[0]) q.pop(), q.push(-k[1]);
      else
        q.push(-k[1]);
    }

    return q.size();
  }
};
