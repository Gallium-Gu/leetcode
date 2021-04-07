// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem5.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        string ans = "";

        for(int i = 0; i < n; i++) {
            dp[i][i] = true; 
        }

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++){
                dp[i][j] = dp[i + 1][j - 1] & (s[i] == s[j]);

                if(dp[i][j] && ans.size() < j - i + 1) {
                    ans = s.substr(i, j + 1);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

