// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem39.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> sum;
    int n = 0;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        dfs(0, candidates, target, 0);
        return ans;
    }

    void dfs(int curSum, vector<int>& candidates, int target, int i) {
        if(i == n) {
            return;
        }

        if(curSum == target) {
            ans.push_back(sum);
            return;
        }

        if(curSum > target) {
            return;
        }

        if(curSum < target) {
            sum.push_back(candidates[i]);
            dfs(curSum + candidates[i], candidates, target, i);
            sum.pop_back();
            dfs(curSum, candidates, target, i + 1);
        }
    }
};
// @lc code=end

