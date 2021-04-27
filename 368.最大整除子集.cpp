#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //dp表示以当前整数为最大数的整除集个数
        int n = nums.size();
        int maxSize = 1;
        int maxVal = nums[0];
        vector<int> dp(nums.size(), 1);
        sort(nums.begin(), nums.end());
        //遍历
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }

                if(dp[i] > maxSize) {
                    maxSize = dp[i];
                    maxVal = nums[i];
                }   
            }
        }
        vector<int> ans;
        if (maxSize == 1)
        {
            ans.push_back(nums[0]);
            return ans;
        }
        
        for (int i = n - 1; i >= 0 && maxSize > 0; i--) {
            if (dp[i] == maxSize && maxVal % nums[i] == 0) {
                ans.push_back(nums[i]);
                maxVal = nums[i];
                maxSize--;
            }
        }
        return ans;
    }
};
// @lc code=end

