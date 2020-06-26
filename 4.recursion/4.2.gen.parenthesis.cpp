/**
 * @file 4.2.gen.parenthesis.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tue Jun 23 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

vector<string> r;

void gen(int remo, string s, int remc) {
    if (!remo && !remc) r.emplace_back(s);
    if (remo > 0) gen(remo - 1, s + '(', remc);
    if (remc > 0 && remc > remo) gen(remo, s + ')', remc - 1);
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        r.clear();
        gen(n - 1, "(", n);

        return r;
    }
};

int main() {
    auto s = new Solution();
    for(auto x: s->generateParenthesis(3)) {
        cout << x << endl;
    }
    return 0;
}