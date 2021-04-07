// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem88.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int i = m - 1, j = n - 1;
        while(index > 0) {
            int x1 = i >= 0 ? nums1[i] : 0;
            int x2 = j >= 0 ? nums2[j] : 0;
            if(x1 > x2) {
                nums1[index] = x1; 
                i--;
            }else{
                nums1[index] = x2;
                j--;
            }
            index--;
        }
    }
};
// @lc code=end

