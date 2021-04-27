#include <vector>
/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sum = 0;

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root) {
            if(root->left) {
                rangeSumBST(root->left, low, high);
            }
            if(root->val >= low && root->val <= high)
                sum += root->val;
            if(root->right) {
                rangeSumBST(root->right, low, high);
            }
        }
        return sum;
    }
};
// @lc code=end

