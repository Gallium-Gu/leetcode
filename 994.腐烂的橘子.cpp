// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem994.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m = 0, n = 0;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        deque<pair<int, int>> rotOrange;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    rotOrange.emplace_back(i, j);
                }
            }
        }

        while(!rotOrange.empty()) {
            int size = rotOrange.size();
            for(int i = 0; i < size; i++) {
                auto [x, y] = rotOrange.front();
                rotOrange.pop_front();
                for(auto direction : directions) {
                    int px = x + direction[0];
                    int py = y + direction[1];
                    if(inArea(px, py) && grid[px][py] == 1) {
                        rotOrange.emplace_back(px, py);
                        grid[px][py] = 2;
                    }
                }
            }
            ans++;
        }

        return ans - 1;
    }

    bool inArea(int x, int y) {
        return x < m && x >= 0 && y < n && y >= 0;
    }
};
// @lc code=end

