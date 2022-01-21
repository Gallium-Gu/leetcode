// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem236.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<stack>
class Solution {
public:
    //通过后续遍历记录第一个找到的点，然后继续遍历找第二个，找到第二个的时候，栈顶就是公共的祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> ST;
        TreeNode* prev = NULL;
        int ans = 0;
        int flag1 = 1, flag2 = 1;
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        system("pause");
        while(root || !ST.empty()) {
            //后续遍历
            if(root) {
                ST.push(root);
                if(flag1) {
                    path1.push_back(root);
                }
                if(flag2) {
                    path2.push_back(root);
                }
                flag1 = (flag1 && root != p) ? 1 : 0;
                flag2 = (flag2 && root != q) ? 1 : 0; 
                if(!flag1 && !flag2)    break;
                root = root -> left;
            }else{
                root = ST.top();
                if(root -> right == NULL || root -> right == prev) {
                    ST.pop();
                    prev = root;
                    root = NULL;
                }else{
                    root = root -> right;
                }
            }
        }
        //遍历path1,2
        for(int i = 1; i < path1.size(); i++) {
            if(path1[i] == path2[i]) {
                continue;
            }else{
                return path1[i - 1];
            }
        }
        return root;
    }
};
// @lc code=end

