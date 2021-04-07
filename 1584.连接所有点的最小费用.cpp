/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int num = points.size();
        vector<bool> flag(num);
        vector<vector<int>> value(num, vector<int>(num));
        vector<int> newValue(num);
        for (int i = 0; i < num; i++){
            for (int j = i; j < num; j++){
                value[i][j] = abs(points[i][0] - points[j][0]) 
                + abs(points[i][1] - points[j][1]);
            }
        }
        int res = 0;
        for (int i = 0; i < num; i++){
            int t = -1;
            for (int j = 0; j < num; j++){
                if(!flag[j] && (t = -1 || newValue[j] < newValue[t])){
                    t = j;
                }
            }
            res += newValue[t];
            flag[t] = 1;
            for (int j = 0; j < num; i++){
                if(!flag[j] && (value[i][j] < newValue[i])){
                    newValue[i] = value[i][j];
                }
            }
        }
        return res;
    }
};
// @lc code=end

