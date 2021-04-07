// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem258.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        if(num > 9) {
            return addDigits(getEverSum(num));
        }

        return num;
    }

    int getEverSum(int n) {
        int res = 0;
        while(n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
};
// @lc code=end

