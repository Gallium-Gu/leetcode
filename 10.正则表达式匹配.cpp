// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem10.h"

using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size();
        int np = p.size();
        int index = 0, n = 0;
        char symbol = ' ';
        while(index < np && n < ns) {
            symbol = p[index];
            //当前是字母
            if((symbol >= 'a' && symbol <= 'z') || symbol == '.') {
                
                //判断下一位是否为重复
                if(index + 1 < np && p[++index] == '*') {
                    while(n < ns && (s[n] == symbol || symbol == '.')) {
                        n++;
                    }
                }else{
                    if(s[n] == symbol || symbol == '.') {
                        n++;
                    }
                }
            }
            index++;
        }

        while(index < np) {
            if(p[index] != '*' && p[index] != '.') {
                return false;
            }
        }

        //返回的时候直接判断n是否为0
        return n == ns;
    }
};
// @lc code=end

