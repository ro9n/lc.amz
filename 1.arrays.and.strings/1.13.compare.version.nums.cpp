/**
 * @file 1.13.compare.version.nums
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday September 18 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  inline int stoi(const string& s, int l, int r) {
    int k = 0;
    for (int i = r, p = 0; i >= l; --i) k += pow(10, p++) * (s[i] - '0');
    return k;
  }

 public:
  int compareVersion(string v1, string v2) {
    int n = v1.size(), m = v2.size();

    for (int i = 0, j = 0, l; i < n || j < m;) {
      l = i; while (i < n && v1[i] != '.') ++i;
      int x = i - 1 < n ? stoi(v1, l, i - 1) : 0;

      l = j; while (j < m && v2[j] != '.') ++j;
      int y = j - 1 < m ? stoi(v2, l, j - 1) : 0;

      if (x < y) return -1;
      else if (x > y) return 1;
      else if (i == n - 1 && j == m - 1) return 0;
      else ++i, ++j;
    }
    return 0;
  }
};

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.size(), m = v2.size();
        
        for(int i = 0, j = 0; i < n || j < m;) {
            int x = 0, y = 0;
            while (i < n && v1[i] != '.') x *= 10, x += v1[i++] - '0';
            while (j < m && v2[j] != '.') y *= 10, y += v2[j++] - '0';
            
            if (x < y) return -1;
            else if (x > y) return 1;
            else ++i, ++j;
        }
        
        return 0;
    }
};