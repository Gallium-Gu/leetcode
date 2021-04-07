// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem995.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=995 lang=cpp
 *
 * [995] K 连续位的最小翻转次数
 */

// @lc code=start
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int ans = 0;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            while(A[i] == 1) {
                i++;
            }

            if(i == n) {
                break;
            }
            
            for(int j = i; j < i + K && j < n; j++) {
                    A[j] ^= 1;
            }
            ans++;
        }

        return ans;
    }
};
// @lc code=end

