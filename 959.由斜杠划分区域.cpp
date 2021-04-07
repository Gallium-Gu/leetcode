// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem959.h"

using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
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
    int row = 0;

public:
    int regionsBySlashes(vector<string>& grid) {
        int ans = 0;
        int row = grid.size();
        int size = row * row * 4;
        UnionSet fa(size);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < row; j++){
                int index = getindex(i, j);
                //组内合并
                if(grid[i][j] == ' '){
                    fa.Union(index, index + 1);
                    fa.Union(index, index + 2);
                    fa.Union(index, index + 3);
                }else if(grid[i][j] == '/'){
                    fa.Union(index, index + 3);
                    fa.Union(index + 1, index + 2);
                }else{
                    fa.Union(index, index + 1);
                    fa.Union(index + 3, index + 2);
                }
                //组间合并
                fa.Union(index + 1, getindex(i, j + 1));
                fa.Union(index + 2, getindex(i + 1, j));
            }
        }
        vector<int> curFa = fa.getFa();
        for (int i = 0; i < size; i++){
            if(curFa[i] == i){
                ans += fa.getSize(i);
            }
        }
        return ans;
    }

    int getindex(int x, int y){
        return (x * row + y) * 4;
    }
};




// @lc code=end

