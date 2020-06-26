/**
 * @file 4.1.letter.combo.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tue Jun 23 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const string t9[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> r;

void append(const string &d, int i, string s) {
  if (i == d.size()) {
    r.emplace_back(s);
    return;
  }

  for (auto c : t9[d[i] - '2']) {
    append(d, i + 1, s + c);
  }
}

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    r.clear();
    if (digits.empty()) return r;
    append(digits, 0, "");

    return r;
  }
};

int main() {
    // 3^N * 4^M
  auto s = new Solution();
  for (auto r : s->letterCombinations("23")) cout << r << endl;

  return 0;
}