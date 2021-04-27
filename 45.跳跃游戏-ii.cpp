#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        int l = 0, int r = nums[0];
        int ans = 0, index = nums[0];
        while(r < n) {
            for (; l < r; l++) {
                index = l + nums[l];
                if(index > r) {
                    
                }
            }
        }
    }
};
// @lc code=end

