// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem867.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> Newmatrix(n, vector<int>(m));
        for(int i = 0; i < m * n; i++) {
            Newmatrix[i / n][i % n] = matrix[i / m][i % n]; 
        }
        return Newmatrix;
    }
};
// @lc code=end

