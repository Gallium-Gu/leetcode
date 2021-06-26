#include <leetcode.h>
#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    void bfs(TreeNode *root, vector<int>& ans) {
        queue<TreeNode*> Mq;
        while(!Mq.empty()) {
            TreeNode *cur = Mq.front();
            Mq.pop();
            if(cur -> left == nullptr && cur -> right == nullptr) {
                ans.push_back(cur -> val);
            }else{
                if(cur -> left != nullptr) {
                    Mq.push(cur -> left);
                }
                if(cur->right != nullptr) {
                    Mq.push(cur -> right);
                }
            }
        }
    } 

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a1;
        vector<int> a2;
        bfs(root1, a1);
        bfs(root2, a2);
        if(a1.size() != a2.size()){
            return false;
        }
        for(int i = 0; i < a1.size(); i++) {
            if(a1[i] != a2[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

