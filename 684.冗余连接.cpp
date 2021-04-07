#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> fa(N+1);
        for (int i = 1; i < N+1; i++){
            fa[i] = i;
        }
        for (auto i: edges){
            Union(fa, i[0], i[1]);
        }
        return *ans.end();
    }

    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        int fa1 = Find(parent, index1);
        int fa2 = Find(parent, index2);
        if(fa1 == fa2){
            ans.push_back({index1, index2});
        }
        parent[fa1] = fa2;
    }
};
// @lc code=end

