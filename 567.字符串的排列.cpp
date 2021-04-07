// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem567.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int ls1 = 0;
        int ls2 = 0;
        for(int i = 0; i < n1; i++){
            ls1 = s1[i] ^ ls1;
        }
        for(int i = 0; i < n1; i++){
            ls2 = s2[i] ^ ls2;
        }
        if(ls1 == ls2){
            return true;
        }
        for(int i = 0; i < n2 - n1 + 1; i++){
            if(ls1 == ls2){
                return true;
            }
            ls2 ^= s2[i];
            ls2 ^= s2[i + n1];
        }
        return false;
    }
};
// @lc code=end

