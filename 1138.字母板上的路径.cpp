#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */

// @lc code=start
class Solution {
public:
    string alphabetBoardPath(string target) {
        int n = target.size();
        string ans = "";
        vector<pair<int, int>> postion;
        postion.emplace_back((target[0] - 'a') / 5, (target[0] - 'a') % 5);
        for(int i = 1; i < n; i++){
            postion.emplace_back((target[i] - 'a') / 5, (target[i] - 'a') % 5);
        }
        int px = 0;
        int py = 0;
        for(auto[x, y] : postion) {
            while(px > x) {
                ans.push_back('U');
                px--;
            }
            while(py > y) {
                ans.push_back('L');
                py--;
            }
            while(px < x) {
                ans.push_back('D');
                px++;
            }
            while(py < y) {
                ans.push_back('R');
                py++;
            }
            
            ans.push_back('!');

        }

        return ans;
    }
};

// @lc code=end

