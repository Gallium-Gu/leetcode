/*
 * @lc app=leetcode.cn id=1461 lang=cpp
 *
 * [1461] 检查一个字符串是否包含所有长度为 K 的二进制子串
 */

// @lc code=start
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> bin;
        int num = 0;
        for(int i  = 0; i < k; i++) {
            num = num << 1;
            num += s[i] - '0';
            bin.insert(num);
        }
        
        for(int i = k; i < s.size(); i++) {
            num = num >> 1;
            num += (s[i] - '0') << (k - 1);
            bin.insert(num);
        }
        
        for(int i = 0; i < 1 << k; i++) {
            if(!bin.count(i)) {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end

