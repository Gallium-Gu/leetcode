#include <leetCode.h>
/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 *
 * [1345] 跳跃游戏 IV
 */

// @lc code=start
class Solution {
public:
    //为了统一,Q和vector中均存储的下标,tp中存储的也是下标(key值不是下标)
    int update(queue<int>& Q, vector<int>& cur, vector<int>& other,
    vector<int>& arr, unordered_map<int, vector<int>>& tp) {
        auto x = Q.front(); Q.pop();
        int step = cur[x];
        //
        for(auto e : tp[arr[x]]) {
            if(cur[e] != -1 || x == e) continue;
            if(other[e] != -1) {
                return cur[x] + other[e] + 1;
            }
            Q.push(e);
            cur[e] = step + 1;
        }

        //向后
        if(x - 1 >= 0 && cur[x - 1] == -1) {
            if(other[x - 1] != -1) {
                return step + other[x - 1] + 1;
            }
            Q.push(x - 1);
            cur[x - 1] = step + 1;
        }
        //向前
        if(x + 1 < cur.size() && cur[x + 1] == -1) {
            if(other[x + 1] != -1) {
                return step + other[x + 1] + 1;
            }
            Q.push(x + 1);
            cur[x + 1] = step + 1;
        }
        return -1;
    }

    int BFS(unordered_map<int, vector<int>>& tp, vector<int>& arr, int n) {
        int ans = 0;
        //claration
        vector<int> S1(n, -1), S2(n, -1);
        queue<int> Q1, Q2;
        //init
        S1[0] = 0;  S2[n - 1] = 0;
        Q1.push(0); Q2.push(n - 1);
        while(!Q1.empty() && !Q2.empty()) {
            if(Q1.size() < Q2.size()) {
                ans = update(Q1, S1, S2, arr, tp);
            }else{
                ans = update(Q2, S2, S1, arr, tp);
            }

            if(ans != -1) {
                return ans;
            }
        }
        return -1;
    }

    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> tp;
        for(int i = 0; i < n; i++) {
            tp[arr[i]].push_back(i);
        }
        return BFS(tp, arr, n);
    }
};
// @lc code=end

