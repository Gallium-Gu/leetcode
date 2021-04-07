// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem59.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n , vector<int>(n));
        int total = n * n + 1;
        int nums = 1;
        int left = 0;
        int lwall = n - 1;
        int dwall = n - 1;
        int down = 0;
        while(nums<total){
            vector<int> row;
            if(nums == total) {
                return ans;
            }
            for(int i = left; i <= lwall; i++) {
                ans[down][i] = nums;
                nums++; 
            }
            if(++down > dwall) {
                break;
            }
            for(int i = down; i <= dwall; i++) {
                ans[i][lwall] = nums;
                nums++;
            }
            if(--lwall < left) {
                break;
            }
            for(int i = lwall; i >= left; i--) {
                ans[dwall][i] = nums;
                nums++;
            }       
            if(--dwall < down) {
                break;
            }
            for(int i = dwall; i >= down; i--) {
                ans[i][left] = nums;
                nums++;
            }
            if(++left > lwall) {
                break;
            }
        }

        return ans;
    }
};
// @lc code=end

