#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] 蛇梯棋
 */

// @lc code=start
class Solution {
public:
//先扁平化，再用DP试试
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> bo;
        int n = board.size();
        vector<int> dp(n * n);
        int times = 0;
        //扁平化
        while(times++ < n * n) {
            int i = (times / n == 2) ? 0 : n - 1; 
            int flag = (times / n == 2) ? 1 :  -1;
            while(i) {
                i += flag;
                bo.push_back(board[times / 2][i]);
            }
        }
        dp[0] = 0;
        for(int i = 0; i < n * n; i++) {
            if(bo[i] == -1){
                for(int s = 1; s <= 6; s++) {
                    if(i + s < n * n)   dp[i + s] = min(dp[i] + 1, dp[i + s]);
                }
            }else{
                dp[bo[i]] = min(dp[i] + 1, dp[bo[i]]);
            }
        }
        return dp[n * n - 1];
    }
};
// @lc code=end

