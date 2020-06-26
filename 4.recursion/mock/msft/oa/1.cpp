/**
 * @file 1.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu Jun 25 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), i = 0, j = 0;

        while (j < n) {
            while(j < n && s[j] != ' ') ++j;
            int k = j - i >> 1, j2 = j - 1;

            while(i < k) {
                swap(s[i++], s[j2--]);
            }

             while(j < n && s[j] == ' ') ++j;
             i = j;
        }

        return s;
    }
};

int main() {
    auto s = new Solution();
    s->reverseWords("Let's take LeetCode contest");
    return 0;
}