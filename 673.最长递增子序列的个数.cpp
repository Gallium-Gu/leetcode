// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include "commoncppproblem673.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        stack<int> mySta;
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> myMap(n);
        for(int i = 0; i < n; i++) {
            if(!mySta.empty() && mySta.top() > nums[i]) {
                ans = mySta.size() > ans ? mySta.size() : ans;
                myMap[ans]++;
                while(!mySta.empty() && mySta.top() > nums[i]) {
                    mySta.pop();
                }
            } 
            mySta.push(nums[i]);
        }
        int max = 0;
        
        for(auto [k, v] : myMap) {
            max = max > k ? max : k;
        }
        
        return myMap[max];
    }
};
// @lc code=end

