#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
class UnionSet
{
private:
    vector<int> fa;
    //浠ndex涓烘牴鑺傜偣鐨勬暟鐩?
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

    vector<int> getFa(){
        return fa;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int num = accounts.size();
        UnionSet unionset(num);
        unordered_map<string, int> emailToIndex;
        unordered_map<int, vector<string>> indexToEmails;
        for (int i = 0; i < num; i++){
            int emailsNum = accounts[i].size();
            for (int j = 1; j < emailsNum; j++){
                if(emailToIndex.find(accounts[i][j]) == emailToIndex.end()){
                    emailToIndex[accounts[i][j]] = i;
                }else{
                    unionset.Union(emailToIndex[accounts[i][j]], i);
                }
            }
        }

        for(auto [k, v] : emailToIndex){
            indexToEmails[unionset.find(v)].emplace_back(k);
        }
        vector<vector<string>> ans;
        for (auto &[k, v] : indexToEmails){
            sort(v.begin(), v.end());
            vector<string> tmp(1, accounts[k][0]);
            tmp.insert(tmp.end(), v.begin(), v.end());
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
// @lc code=end

