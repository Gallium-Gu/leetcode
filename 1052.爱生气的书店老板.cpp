#include <vector>
#include <algorithm>
/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<int> prev(grumpy.size());
        if(minutes >= customers.size()) {
            return accumulate(grumpy.begin(), grumpy.end(), 0);
        }
        int sum = accumulate(customers.begin(), customers.end(), 0);
        for(int i = 0; i < minutes; i++) {
            sum -= grumpy[i] * customers[i];
        }
        int ans = 0;
        for (int i = minutes; i < grumpy.size(); i++)
        {
            ans = max(ans, sum);
            sum -= grumpy[i - minutes] * customers[i - minutes];
            sum += customers[i];
        }
        return ans;
    }
};
// @lc code=end

