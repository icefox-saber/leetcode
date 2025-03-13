/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {

    vector<pair<TreeNode *, unsigned long long>> thislevel;
    vector<pair<TreeNode *, unsigned long long>> nextlevel;

    thislevel.emplace_back(root, 1UL);
    unsigned long long res = 1;
    while (!thislevel.empty()) {

      res = max(res, thislevel.back().second - thislevel.front().second + 1);
      for (auto node : thislevel) {
        if (node.first->left)
          nextlevel.emplace_back(node.first->left, node.second * 2);
        if (node.first->right)
          nextlevel.emplace_back(node.first->right, node.second * 2 + 1);
      }
      thislevel = move(nextlevel);
    }

    return res;
  }
};
// @lc code=end
