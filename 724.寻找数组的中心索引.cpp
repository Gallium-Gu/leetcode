// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem724.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n + 1);
        if(n <= 1){
            return -1;
        }
        presum[0] = 0;
        for(int i = 1; i < n + 1; i++){
            presum[i] = presum[i - 1] + nums[i - 1]; 
        }
        int sum = presum[n];
        for(int i = 0; i < n; i++){
            if(sum - nums[i] == presum[i] * 2){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

