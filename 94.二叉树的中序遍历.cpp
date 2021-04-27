#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> tree;
        stack<int> treePlus;
        vector<int> ans;
        tree.push(root);
        treePlus.push(2);
        while(!tree.empty()) {
            TreeNode *curNode = tree.top();
            //空结点
            if(curNode == NULL) {
                tree.pop();
                treePlus.pop();
                continue;
            }
            //左边没有弹出
            if(treePlus.top() == 2) {
                tree.push(curNode->left);
                treePlus.pop();
                treePlus.push(1);
                treePlus.push(2);
            }
            //左边已经弹出
            if(treePlus.top() == 1) {
                tree.pop();
                tree.push(curNode->right);
                ans.push_back(curNode->val);
                treePlus.pop();
                treePlus.push(2);
            }
        }
        return ans;
    }
};
// @lc code=end

