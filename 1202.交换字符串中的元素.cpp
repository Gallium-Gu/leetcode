#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        int groupe = pairs.size();
        vector<int> fa(n);
        vector<vector<int>> isConected(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            fa[i] = i;
            isConected[pairs[i][0]][pairs[i][1]] = 1;
        }
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if(isConected[i][j] = 1){
                    merge(fa,i,j);
                }
            }
        }
        map<int, vector<int>> needSort;
        for (int i = 0; i < n; i++){
            needSort[fa[i]].emplace_back(i);
        }
        for (int i = 0; i < needSort.size(); i++){
            sort(needSort[i], s);
        }
        return s;
    }

    void merge(vector<int>& fa ,int i,int j){
        fa[Find(fa,i)] = Find(fa,j);
    }

    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }
    
    void sort(vector<int> nums,string s){
        int len = nums.size();
        for (int i=0; i<len-1; i++) 
        for (int j=0; j<len-1-i; j++) { 
            if (s[nums[j]] > s[nums[j+1]]) {
                swap(s[nums[j]], s[nums[j + 1]]);
            }
        }
    }
};
// @lc code=end

