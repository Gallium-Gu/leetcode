#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<vector<int>> ans;
        unordered_map<int, int> Mymap;
        Mymap[1] = 0;
        for(auto i: edges){
            if(Mymap.count(i[0]) && Mymap[i[0]] <= Mymap[i[1]]){
                ans.push_back({i[0], i[1]});
            }else{
                Mymap[i[1]] = Mymap[i[0]] + 1;
            }
        }
        return ans.back();
    }
};
// @lc code=end

