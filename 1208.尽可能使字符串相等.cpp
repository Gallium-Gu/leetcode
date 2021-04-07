#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int n = s.length();
        vector<int> cost(n);
        for(int i = 0; i < n; i++){
            cost[i] = abs(s[i] - t[i]);
        }
        sort(cost.begin(), cost.end());
        for(int i = 0; i < n; i++){
            if(cost[i] <= maxCost){
                ans++;
                maxCost -= cost[i];
            }else{
                return ans;
            }
        }
        return ans;
    }
};
// @lc code=end

