/**
 * @file 3.11.diameter.of.btree
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

int best;

int dfs(TreeNode *h) {
  if (!h) return 0;
  int l = dfs(h->left), r = dfs(h->right);
  best = max(best, l + r);
  return 1 + max(l, r);
}

class Solution {
 public:
  int diameterOfBinaryTree(TreeNode *h) {
    best = 0; dfs(h); return best;
  }
};