// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem978.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int len = A.size();
        int up = 1, down = 1;
        int ans = 1;
        for (int i = 1; i < len; i++) {
            if (A[i] > A[i - 1]) { up = down + 1; down = 1; }
            else if (A[i] < A[i - 1]) { down = up + 1; up = 1; }
            else { up = down = 1; }
            ans = max(ans, max(up, down));
        }
        return ans;
    }
};
// @lc code=end

