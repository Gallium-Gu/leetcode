// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem29.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        int i = 0;
        int nums = divisor; 
        int ans = 1;
        while(divisor < dividend) {
            ans *= 2;
            divisor = divisor << 1;
        }

        ans -= 2;
        divisor = divisor >> 1;
        while(nums < divisor) {
            nums += nums;
            ans++;
        }

        return ans;
    }
};
// @lc code=end

