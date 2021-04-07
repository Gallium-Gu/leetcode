#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //键为分母，值为以对应分母的分子式下标
        unordered_map<char, vector<int>> myMap;
        for (int i = 0; i < equations.size(); i++){
            myMap[equations[i][0][0]].push_back(i);
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++){
            
        }
    }
};
// @lc code=end

