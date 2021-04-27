// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem131.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
    vector<vector<string>> ans;
    vector<string> row;
    int n = 0;
public:
    vector<vector<string>> partition(string s) {
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

        dfs(dp, 0, s);

        return ans;

    }

    void dfs(vector<vector<bool>>& dp, int index, string s) {
        if(index == n) {
            ans.push_back(row);
            return;
        }

        for(int i = index; i < n; i++) {
            if(dp[index][i] == true) {
                row.push_back(s.substr(index, i - index + 1));
                dfs(dp, i + 1, s);
                row.pop_back();
            }
        }
        //我实打实打算
    }
};
// @lc code=end

