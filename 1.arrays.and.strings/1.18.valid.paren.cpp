/**
 * @file 1.18.valid.paren
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday September 19 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> m = {
    {'(', ')'},
    {'{', '}'},
    {'[', ']'},
};

inline bool isc(int c) { return c == ')' || c == '}' || c == ']'; }
inline int cmp(int c) { return m[c]; }

class Solution {
 public:
  bool isValid(string s) {
    stack<int> S;

    for (auto c : s) {
      if (isc(c)) {
        if (S.empty()) return 0;
        int top = S.top(); S.pop();
        if (top != c) return 0;
      } else {
        S.push(cmp(c));
      }
    }

    return S.empty();
  }
};
