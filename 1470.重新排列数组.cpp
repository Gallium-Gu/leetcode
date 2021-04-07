#include <vector>
#include <stdlib.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        int index = 0;
        for(int i = 0; i < n; i++) {
            ans[index++] = nums[i];
            ans[index++] = nums[i + n]; 
        }

        return ans;
    }
};
// @lc code=end

