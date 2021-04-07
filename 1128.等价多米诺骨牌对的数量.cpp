#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<pair<int, int>, int> myMap;
        int ans = 0;
        for(auto i : dominoes){
            if(i[0] > i[1])
                swap(i[0], i[1]);
            myMap[{i[0], i[1]}]++;
        }
        for(auto i : myMap){
            int n = i.second;
            ans += n * (n - 1) / 2;
        }
        return ans;
    }
};
// @lc code=end

