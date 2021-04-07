// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem130.h"

using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
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
        for (int i = 0; i < size; i++){
            fa[i] = i;
            rootSize[i] = 1;
        }
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
        if(fa[index1] != index1){
            fa[index1] = find(fa[index1]);
        }
        return fa[index1];
    }
    
    int getSize(int index){
        return rootSize[find(index)];
    }

    vector<int>& getFa(){
        return fa;
    }
};

class Solution {
private:
    int row;
    int line;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    void solve(vector<vector<char>>& board) {
        row = board.size();
        line = board[0].size();
        int size = row * line;
        UnionSet xoArea(size + 1);
        vector<int>& fa = xoArea.getFa();
        for (int i = 0; i < row; i++){
            fa[getIndex(i, 0)] = size;
        }
        for (int i = 0; i < line; i++){
            fa[i] = size;
        }
        for (int i = 0; i < row; i++){
            for (int j = 0; j < line; j++){
                if(board[i][j] == 'O'){
                    for(auto direction :directions){
                        int newX = i + direction[0];
                        int newY = j + direction[1];
                        if(inArea(newX,newY)){
                            xoArea.Union(getIndex(i, j), getIndex(newX, newY));
                        }
                    }
                }
            }
        }
        int wall = xoArea.find(size);
        for(auto i : fa){
            if(xoArea.find(i) == wall){
                board[i / row][i % row] == 'x';
            }
        }
    }

    int getIndex(int x,int y){
        return x * row + y;
    }

    bool inArea(int x, int y){
        return x < row || y < line || x >= 0 || y >= 0;
    }
};
// @lc code=end

