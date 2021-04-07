// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem224.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int n =s.size();
        int ans = 0;
        int num = 0;
        int sign = 1;
        stack<int> character;
        character.push(1); 
        for(int i = 0; i < n; ) {
            if(s[i] == ' ') {
                i++;
                continue;
            }else if(s[i] == '+') {
                sign = character.top();
                i++;
            }else if(s[i] == '-') {
                sign = character.top() * -1;
                i++;
            }else if(s[i] == '(') {
                character.push(sign);
                i++;
            }else if(s[i] == ')') {
                character.pop();
                i++;
            }else{
                num = 0;
                while(i < n && s[i] > '0' && s[i] < '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                ans += sign * num;
            }
            
        }

        return ans;
    }
};
// @lc code=end

