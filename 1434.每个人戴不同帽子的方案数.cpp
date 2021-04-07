#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1434 lang=cpp
 *
 * [1434] 每个人戴不同帽子的方案数
 */

// @lc code=start
class Solution {
    vector<bool> flag(40);
    int ans = 0;
public:
    int numberWays(vector<vector<int>>& hats) {
        
        sort(hats.begin(), hats.end(), cmp);

        dfs(0, hats);

        return ans;
    }

    void dfs(int index, vector<vector<int>>& hats) {
        if(index == hats.size()) {
            ans++;
            return;
        }

        for(auto hat : hats[index]) {
            if(flag[hat]) {
                flag[hat] = false;
                dfs(index + 1, hats);
                flag[hat] = true;
            }
        }
    }

    bool cmp(const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
    }
};
// @lc code=end

