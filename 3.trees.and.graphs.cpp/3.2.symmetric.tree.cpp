/**
 * @file 3.2.symmetric.tree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday September 20 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isSymmetric(TreeNode *r) {
    queue<TreeNode *> q;
    q.push(r); q.push(r);

    while (!q.empty()) {
      auto f1 = q.front(); q.pop();
      auto f2 = q.front(); q.pop();

      if (!f1 && !f2)
        continue;
      else if (!f1 || !f2)
        return 0;
      else if (f1->val != f2->val)
        return 0;
      else {
        q.push(f1->left), q.push(f2->right);
        q.push(f1->right), q.push(f2->left);
      }
    }

    return 1;
  }
};
