// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem779.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号
 */

// @lc code=start
class Solution {
public:
    int kthGrammar(int N, int K) {
        string word = "0";
        if(N == 1){
            return word[0] - '0';
        }
        for(int i = 1; i < N; i++){
            word = help(word);
        }
        return word[K - 1] - '0';
    }

    string help(string word){
        string ans = "";
        for(auto letter : word){
            if(letter == '1'){
                ans += "10";
            }else{
                ans += "01";
            }
        }
        return ans;
    }
};
// @lc code=end

