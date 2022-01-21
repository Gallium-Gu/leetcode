#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
public:
    //const int INT_MAX = 2147483647;
    int m, n;
    vector<vector<int>> dicts{{0,-1},{0,1},{1,0},{-1,0}};
    bool inArea(int x, int y) {
        return x>=0 && x<m && y<n && y>=0;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //Q中存储的是零的坐标
        queue<pair<int,int>> Q;
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    Q.emplace(i, j);
                }
            }
        }
        int step = 1;
        while(!Q.empty()){
            int size = Q.size();
            while(size) {
                auto [x, y] = Q.front();
                for (auto dic : dicts)
                {
                    int px = x + dic[0];
                    int py = y + dic[1];
                    if(inArea(px, py) && (ans[px][py] == INT_MAX)) {
                        Q.emplace(px, py);
                        ans[px][py] = step;
                    }
                }
                Q.pop();
                size--;
            }
            step++;
        }
        return ans;
    }
};
// @lc code=end

