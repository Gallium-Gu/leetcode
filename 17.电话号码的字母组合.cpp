// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    vector<string> numToStr{"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    int n = 0;
public:
    vector<string> letterCombinations(string digits) {  
        n = digits.size(); 
        if(n == 0){
            return {};
        }
        numToletter(0, digits, "");
        return ans;
    }

    void numToletter(int i, string digits, string word){
        if(i == n){
            ans.push_back(word);
            return;
        }
        for(auto letter : numToStr[digits[i] - '0']){
            numToletter(i + 1, digits, word + letter);
        }
    }
};
// @lc code=end

