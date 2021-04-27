// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem617.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */

// @lc code=start
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* NewHead = new TreeNode(root1 -> val + root2 -> val);
        LeftTrees(root1 -> left, root2 -> left, NewHead);
        RightTrees(root1 -> right, root2 -> right, NewHead);
        return NewHead;
    }

    void LeftTrees(TreeNode* root1, TreeNode* root2, TreeNode* last) {
        //当前结点生成
        TreeNode* res = new TreeNode();
        if(root1 && root2) {
            res -> val = root1 -> val + root2 -> val;
            root1 = root1 -> left;
            root2 = root2 -> left;
        }else if(root1) {
            res -> val = root1 -> val;
            root1 = root1 -> left;
        }else if(root2){
            res -> val = root2 -> val;
            root2 = root2 -> left;
        }else{
            return;
        }
        last -> left = res;
        //进入左右子树的递归
        LeftTrees(root1, root2, res);
        RightTrees(root1, root2, res);
     }

     void RightTrees(TreeNode* root1, TreeNode* root2, TreeNode* last) {
        //当前结点生成
        TreeNode* res = new TreeNode();
        if(root1 && root2) {
            res -> val = root1 -> val + root2 -> val;
            root1 = root1 -> right;
            root2 = root2 -> right;
        }else if(root1) {
            res -> val = root1 -> val;
            root1 = root1 -> right;
        }else if(root2){
            res -> val = root2 -> val;
            root2 = root2 -> right;
        }else{
            return;
        }
        last -> right = res;
        //进入左右子树的递归
        LeftTrees(root1, root2, res);
        RightTrees(root1, root2, res);
     }
};
// @lc code=end

