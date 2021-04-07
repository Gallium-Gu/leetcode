// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem395.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> count;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            count[s[i]]++;
        }

        int l = 0, r = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int length = 0;
            unordered_map<char, int> Wincount;
            while(i < n && count[s[i]] >= k) {
                length++;
                Wincount[s[i]]++;
                i++;
            }

            ans = max(ans, length);
            
            for(auto [k, v] : Wincount) {
                count[k] -= v;
            }

        }

        return ans;
    }
};
// @lc code=end

