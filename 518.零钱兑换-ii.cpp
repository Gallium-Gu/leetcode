#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);
        for(int i = 0; i < n; i++) {
            dp[coins[i]] = 1;
        }
        for(int i = 0; i < amount + 1; i++) {
            for(int j = 0; j < n; i++) {
                if(i - coins[j] >= 0 && dp[i - coins[j]] != 0)
                    dp[i] = dp[i - coins[j]] + 1;
            }
        }
        return dp[amount];
    }
};
// @lc code=end

