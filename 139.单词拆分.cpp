#include <vector>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDic(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - i; j++) {
                if(dp[j] && wordDic.find(s.substr(i, j)) != wordDic.end()) {
                    dp[j + i] = true;
                }else{
                    dp[j + i] = false;
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end

