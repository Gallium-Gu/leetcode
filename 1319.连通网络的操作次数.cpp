#include <leetcode.h>
/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
 */

// @lc code=start
class UnionSet
{
private:
    vector<int> fa;
    //以index为根节点的数目
    vector<int> rootSize;

public:
    int ans = 0;
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
            ans++;
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

    int getFaNums(){
        int res = 0;
        for (int i = 0; i < fa.size(); i++){
            if(i == fa[i]){
                res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionSet unionSet(n);
        for (auto i : connections){
            unionSet.Union(i[0], i[1]);
        }
        int nums = unionSet.getFaNums();
        if(unionSet.ans <= nums - 1){
            return unionSet.ans;
        }
        return -1;
    }
};
// @lc code=end

