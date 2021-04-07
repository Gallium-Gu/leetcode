// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem227.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int i = 0;
        stack<int> nums;
        char sign = '+';
        int ans = 0;
        while(i < n) {
            int num = 0;
            while(i < n && s[i] >= '0' && s[i] < '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            if(s[i] == ' ') {
                i++;
            }else if(sign == '+') {
                nums.push(num);
            }else if(sign == '-') {
                nums.push(-1 * num);
            }else if(sign == '*') {
                int temp = nums.top() * num;
                nums.pop();
                nums.push(temp);
            }else if(sign == '/') {
                int temp = nums.top() / num;
                nums.pop();
                nums.push(temp);
            }
            sign = s[i];
            i++;
        }

        while(!nums.empty()) {
            ans += nums.top();
            nums.pop();
        }

        return ans;
    }
};
// @lc code=end

