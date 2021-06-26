#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<> abb;
        unordered_map<string> myMap;
        int n = words.size()
        for (int i = 0; i < n; i++)
        {
            myMap[words[i]]++;
        }

        for(auto [k,v] : myMap){
            if(abb.size() < k) {
                abb.push(k);
            }
        }
        
    }
};
// @lc code=end

