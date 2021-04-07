// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem3.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<bool> letter(26);
        int l = 0, r = 0;
        int ans = 0;
        while(r < n) {
            if(letter[s[r] - 'a'] == false) {
                letter[s[r] - 'a'] = true;
                r++;               
                continue;
            }
            ans = max(ans, r - l);

            while(letter[s[r] - 'a'] == true) {
                letter[s[l] - 'a'] = false;
                l++;
            }
        }
        return ans;
    }
};
// @lc code=end

