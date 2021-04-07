#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */

// @lc code=start
class Solution {
private:
    int row;
    int line;
    int hitTimes;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        row = grid[0].size();
        line = grid.size();
        hitTimes = hits.size();
        vector<vector<int>> copyBoard(grid);
        //打掉砖块
        for(auto i:hits){
            copyBoard[i[0]][i[1]] = 0;
        }
        //屋顶序号
        int size = row * line;
        UnionSet unionSet(size + 1);
        //初始化连接屋顶的砖块
        for (int i = 0; i < row;i++){
            if(copyBoard[0][i] == 1){
                unionSet.Union(i, size);
            }
        }
        //初始化图
        for (int i = 0; i < line;i++){
            for (int j = 0; j < row; j++){
                if (copyBoard[i][j - 1] == 1){
                    unionSet.Union(getIndex(i, j - 1), getIndex(i, j));
                }
                if(copyBoard[i-1][j] == 1){
                    unionSet.Union(getIndex(i - 1, j), getIndex(i, j));
                }
            }
        }
        vector<int> res(hitTimes);
        //开始还原方块
        for (int i = hitTimes - 1; i > 0; i--){
            int px = hits[i][0];
            int py = hits[i][1];
            int original = unionSet.getSize(size);
            //遍历四个方向
            for(auto direction : directions){
                int newx = hits[i][0] + direction[0];
                int newy = hits[i][1] + direction[1];
                if(copyBoard[newx][newy] == 1){
                    unionSet.Union(getIndex(newx, newy), getIndex(px, py));
                }
            }
            //与屋顶连接的数量
            int currtentBlock = unionSet.getSize(size);
            copyBoard[px][py] = 1;
            res[i] = max(0, currtentBlock - original - 1);
        }

        return res;
    }

    bool whetherOut(int x,int y){
        return x > row || y > row || x < 0 || y < 0;
    }

    int getIndex(int x,int y){
        return x * row + y;
    }
};

class UnionSet
{
private:
    vector<int> fa;
    //以index为根节点的数目
    vector<int> rootSize;

public:
    UnionSet(int size){
        fa.resize(size);
        rootSize.resize(size);
    }

    void Union(int index1, int index2){
        int root1 = find(index1);
        int root2 = find(index2);
        if(root1 == root2){
            return;
        }
        fa[root1] = root2;
        rootSize[root2] += rootSize[root1];
    }

    int find(int index1){
        if(fa[index1] == index1){
            return index1;
        }
        fa[index1] = find(fa[index1]);
    }
    
    int getSize(int index){
        return rootSize[find(index)];
    }
};

// @lc code=end

