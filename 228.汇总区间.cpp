// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem228.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        // 这里需要++right是因为找的区间是2端闭区间，+1刚好移动到下一个需要好的区间。
        for (int right = 0; right < nums.size(); ++right) {
            int left = right; // 设置查找区间的起点
            // 在查找的同时，也在移动外层指针right。right < nums.size() - 1避免越界
            while (right < nums.size() - 1 && nums[right] + 1 == nums[right + 1])
                ++right;
            if (left == right) result.push_back(to_string(nums[left]));
            else result.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
        }
        return result;
    }
};

// @lc code=end

