/**
 * @file 4.1.letter.combo.revisited
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 01 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const string t9[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> ans;

// 3ᴺx4ᴹ
void choose(const string &s, const string &k, const int &i) {
  if (i == s.size()) {
    if (!k.empty()) ans.emplace_back(k);
    return;
  }
  for(auto c: t9[s[i] - '0']) {
    choose(s, k + c, 1 + i);
  }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        ans.clear(); choose(digits, "", 0); return ans;
    }
}; 