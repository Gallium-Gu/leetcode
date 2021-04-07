// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem400.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第N个数字
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        int start = 1;
        int digit = 1;
        int bucket = 9;
        while(bucket < n) {
            n -= bucket;
            digit++;
            start *= 10;
            bucket = digit * start * 9;
        }

        long nums = start + (n - 1) / digit;
        return getIndex(nums, (n - 1) % digit);
    }

    int getIndex(long val, int index ) {
        for(int i = 0; i < index; i++) {
            val /= 10;
        }

        return val % 10;
    }
};
// @lc code=end

