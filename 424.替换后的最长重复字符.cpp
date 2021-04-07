// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem424.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 1;
        int n = s.length();
        int times = 0;
        int max = 1;
        for(int i = 0; i < n; i++){
            ans = 1;
            int cur = i;
            while(i + 1 < n){
                if(s[cur] == s[i + 1]){
                    ans++;
                }else if(times < k){
                    ans++;
                    times++;
                }else{
                    break;
                }
                i++;
                max = ans > max? ans:max;
            }
            i = cur;
        }
        return max;
    }
};
// @lc code=end

