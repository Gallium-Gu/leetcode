#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=1579 lang=cpp
 *
 * [1579] 保证图可完全遍历
 */

// @lc code=start
class UnionSet
{
private:
    vector<int> fa;
    //以index为根节点的数目
    vector<int> rootSize;

    vector<int> ans;
public:
    UnionSet(int size){
        fa.resize(size);
        rootSize.resize(size);
        for (int i = 0; i < size; i++){
            fa[i] = i;
            rootSize[i] = 1;
        }
    }

    bool Union(int index1, int index2, int i){
        int root1 = find(index1);
        int root2 = find(index2);
        if(root1 == root2){
            ans.push_back(i);
            return false;
        }
        fa[root1] = root2;
        rootSize[root2] += rootSize[root1];
        return true;
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
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        UnionSet Alice(n + 1);
        UnionSet Bob(n);
        UnionSet AliceAndBob(n);
        for(int i = 0; i < n; i++){
            if(edges[i][0] == 3){
                Alice.Union(edges[i][1],edges[i][2], i);
                Bob.Union(edges[i][1],edges[i][2], i);
            }           
        }
        for(int i = 0; i < n; i++){
            if(edges[i][0] == 1){
                if(!Alice.Union(edges[i][1],edges[i][2], i)){
                    ans++;
                }
            }else if(edges[i][0] == 2){
                if(!Bob.Union(edges[i][1],edges[i][2], i)){
                    ans++;
                }
            }           
        }
        return ans;
    }
};
// @lc code=end

