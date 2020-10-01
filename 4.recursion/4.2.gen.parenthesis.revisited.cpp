/**
 * @file 4.2.gen.parenthesis.revisited
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 01 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

vector<string> ans;
// Our complexity analysis rests on understanding how many elements there are in
// generateParenthesis(n). This analysis is outside the scope of this article,
// but it turns out this is the n-th Catalan number which is bounded asymptotically 
// by 4ⁿ/n√n → O(4ⁿ/√n)
void gen(int ro, int rc, string s) {
  if (ro == rc && rc == 0) ans.emplace_back(s);

  if (ro > 0) gen(ro - 1, rc + 1, s + '(');
  if (rc > 0) gen(ro, rc - 1, s + ')');
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        ans.clear(); gen(n, 0, ""); return ans;
    }
};

