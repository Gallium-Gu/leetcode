#include <vector>
#include <bitset>
/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> x1(x);
        bitset<32> y1(y);
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            ans += x1[i] ^ y1[i];
        }
        return ans;
    }
};
// @lc code=end

