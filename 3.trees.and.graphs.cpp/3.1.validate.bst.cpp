/**
 * @file 3.1.validate.bst
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
  bool validate(TreeNode *r, TreeNode *lb, TreeNode *ub) {
    if (!r) return 1;
    else if ((ub && r->val >= ub->val) || (lb && r->val <= lb->val)) return 0;
    return validate(r->left, lb, r) && validate(r->right, r, ub);
  }
 public:
  bool isValidBST(TreeNode *r) {
    return validate(r, 0, 0);
  }
};
