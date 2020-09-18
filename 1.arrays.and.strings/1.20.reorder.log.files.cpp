/**
 * @file 1.20.reorder.log.files
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday September 19 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;
inline int cmp(const string& a, const string& b) {
  int i = a.find(' ') , j = b.find(' ');

  if (isalpha(a[i + 1]) ^ isalpha(b[j + 1]))
    return isalpha(a[i + 1]);  // a + d
  else if (isdigit(a[i + 1]))
    return 0;  // d

  // a
  int d = a.substr(i + 1).compare(b.substr(j + 1));
  return d ? d < 0 : a.substr(0, i - 1).compare(b.substr(0, j - 1));
}

class Solution {
 public:
  vector<string> reorderLogFiles(vector<string>& l) {
    stable_sort(l.begin(), l.end(), cmp);
    return l;
  }
};
