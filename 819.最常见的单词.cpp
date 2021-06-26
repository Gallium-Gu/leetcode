#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */

// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        stringstream s(paragraph);
        string word;
        unordered_map<string, int> abb;
        unordered_map<string, int> bba;
        for(auto e : banned) {
            bba[e]++;
        };
        while(s >> word){
            if(!bba.count(word)) {
                abb[word]++;
            } 
        }
        return (*max_element(abb.begin(), abb.end())).first;    
    }
};
// @lc code=end

