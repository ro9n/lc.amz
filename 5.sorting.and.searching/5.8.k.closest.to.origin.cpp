/**
 * @file 5.8.k.closest.to.origin
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 03 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long

typedef vector<int> vi;
typedef pair<ll, vi> puzzy;

inline ll dist(int x, int y) { return x * x + y * y; }

inline int cmp(puzzy &a, puzzy &b) {
  return a.first < b.first;
}

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
    priority_queue<puzzy, vector<puzzy>, decltype(&cmp)> q(cmp);
    vector<vi> ans;

    for (auto p : points) {
      q.push({dist(p[0], p[1]), p});
      if (q.size() > K) q.pop();
    }

    while (!q.empty()) {
      ans.emplace_back(q.top().second);
      q.pop();
    }

    return ans;
  }
};
