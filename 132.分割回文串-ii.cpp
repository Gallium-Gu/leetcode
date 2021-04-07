// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem132.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
    int n = 0;
public:
    int minCut(string s) {
        n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));

         for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = true;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
            }
        }


        vector<int> dp2(n, INT_MAX);
        dp2[0] = 1;
        for(int i = 0; i < n; i++) {
            if(dp[0][i] == true){
                dp2[i] = 0;
            }else{
                for(int j = 0; j < i; j++) {
                    if(dp[j + 1][i] == true)
                    dp2[i] = min(dp2[i], dp2[j] + 1);
                }
            }
            
        }

        return dp2[n - 1];
    }
};
// @lc code=end

