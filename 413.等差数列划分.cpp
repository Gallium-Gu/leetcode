// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem413.h"

using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 0;
            dp[i][i + 1] = nums[i + 1] - nums[i]; 
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i + 1][j] == nums[i] - nums[i - 1]) {
                    dp[][] = 
                }
                   
                }
            }
        }
    }
};
// @lc code=end

