/**
 * @file 1.10.rotate.image
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday September 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();

        for(int i = 0; i < n; ++i) for(int j = i; j < n; ++j) swap(m[i][j], m[j][i]);
        for(int i = 0; i < n; ++i) for(int j = 0; j < n >> 1; ++j) swap(m[i][j], m[i][n - 1 - j]);
    }
};