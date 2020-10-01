/**
 * @file 3.10.lca.of.btree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 01 2020
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
  TreeNode *lowestCommonAncestor(TreeNode *h, TreeNode *p, TreeNode *q) {
    if (!h) return 0;
    else if (h == p || h == q) return h;

    TreeNode *l = lowestCommonAncestor(h->left, p, q),
             *r = lowestCommonAncestor(h->right, p, q);

    if (l && r) return h;
    else if (l) return l;
    else return r;
  }
};