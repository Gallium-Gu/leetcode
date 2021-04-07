// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem120.h"

using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //到达第i行第n个结点所需路径和，滚动省去行数
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        for(int i = 1; i < n; i++) {
            for(int j = i; j >= 0; j--) {
                if(j == 0) {
                    dp[j] = dp[j] + triangle[i][j]; 
                }else if(j == i){
                    dp[j] = dp[j - 1] + triangle[i][j];
                }else{
                    dp[j] = min(triangle[i][j] + dp[j], triangle[i][j] + dp[j - 1]);
                }
            }
        }

        return *min_element(dp.begin(), dp.end());
    }
};
// @lc code=end

