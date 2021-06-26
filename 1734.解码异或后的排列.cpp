#include <vector>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 *
 * [1734] 解码异或后的排列
 */

// @lc code=start
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int total = 0;
        vector<int> ans;
        int n = encoded.size();
        for (int i = 1; i < n + 2; i++) {
            total ^= i;
        }

        for (int i = 1; i < n; i += 2) {
            total ^= encoded[i];
        }
        ans.push_back(total);
        for (int i = 0; i < n; i++) {
            total ^= encoded[i];
            ans.push_back(total);
        }
        return ans;
    }
};
// @lc code=end

