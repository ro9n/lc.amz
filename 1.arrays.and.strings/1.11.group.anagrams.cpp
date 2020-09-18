/**
 * @file 1.11.group.anagrams
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday September 18 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

inline string h(string s) {
    sort(s.begin(), s.end());
    return s;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m; vector<vector<string>> r;
        for(auto s: strs) m[h(s)].emplace_back(s);

        for(auto it = m.begin(); it != m.end(); ++it) r.emplace_back(it->second);
        return r;
    }
};
