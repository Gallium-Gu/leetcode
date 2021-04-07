#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */

// @lc code=start
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> p(n);
        for(int i = 0; i < n; i++) p[i] = i;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Union(p ,i, j);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(p[i] == i) cnt++;
        }
        return n-cnt;
    }

    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2);
    }
};
// @lc code=end

