// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1004.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < n){
            int curK = 0;
            r = l;
            while(r < n && ((A[r] == 0 && curK++ < K) || A[r] == 1)){
                r++;
            }
            ans = max(ans, r - l);
            l = r;
        }
        return ans;
    }
};
// @lc code=end

