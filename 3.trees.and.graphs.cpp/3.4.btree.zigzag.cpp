/**
 * @file 3.4.btree.zigzag
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday September 20 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* r) {
        vector<vi> neighbours; queue<TreeNode*> q;
        q.push(r); int k = 0;

        while(!q.empty()) {
          int n = q.size(); vi kneighbours; ++k;

          for(int i = 0; i < n; ++i) {
            auto f = q.front(); q.pop();
            if (!f) continue;
            kneighbours.emplace_back(f->val);
            q.push(f->left), q.push(f->right);
          }

          if (!kneighbours.empty()) neighbours.emplace_back(kneighbours);
          if (!kneighbours.empty() && !(k & 1))
            reverse(neighbours[k - 1].begin(), neighbours[k - 1].end());
        }

        return neighbours;
    }
};