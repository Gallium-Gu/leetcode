// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem491.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> squence;
    int n = 0;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int i) {
        if(i == n && squence.size() > 1) {
            ans.push_back(squence);
            return;
        }

        if(squence.empty() || nums[i] >= squence.back()) {
            squence.push_back(nums[i]);
            dfs(nums, i + 1);
            squence.pop_back();
        }
        
        if(nums[i] != squence.back()) {
            dfs(nums,i + 1);
        }
    }
};
// @lc code=end

