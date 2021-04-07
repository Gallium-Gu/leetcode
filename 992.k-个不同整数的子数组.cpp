// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem992.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        while(left < n){
            right = left;
            unordered_map<int, int> count;
            while(right < n && count.size() < K){
                count[A[right]]++;
                right++;
            }
            if(count.size() < k){
                return ans;
            }
            ans++;
            while(right < n && count.count(A[right]) == 1){
                ans++;
                right++;
            }
            left++;
        }
        return ans;
    }
};
// @lc code=end

