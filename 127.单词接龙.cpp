// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include "commoncppproblem127.h"

using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int update(queue<string>& Q, unordered_map<string, int>& cur, 
    unordered_map<string, int>& other, unordered_set<string>& Set) {
        auto x = Q.front(); Q.pop();
        int n = x.size();
        
        for(int i = 0; i < n; i++) {
            int step = cur[x];
            for(int off = 0; off < 26; off++) {
                string a = x;
                a[i] = 'a' + off;
                if(!Set.count(a) || cur.count(a)) {
                    continue;
                }
                if(other.count(a)) {
                    return step + other[a] + 1;
                }
                Q.push(a);
                cur.emplace(a, step + 1);
            }
        }
        return -1;
    }

    int BFS(unordered_set<string>& Set, string beginWord, string endWord) {
        int ans = 0;
        //claration
        queue<string> Q1, Q2;
        unordered_map<string, int> M1, M2;
        //init
        Q1.push(beginWord); Q2.push(endWord);
        M1[beginWord] = 0;  M2[endWord] = 1;

        while(!Q1.empty() && !Q2.empty()) {
            if(Q1.size() > Q2.size()) {
                ans = update(Q2, M2, M1, Set);
            }else{
                ans = update(Q1, M1, M2, Set);
            }
            if(ans != -1) {
                cout << ans;
                return ans;
            }
        }
        return -1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> Set(wordList.begin(), wordList.end());
        return BFS(Set, beginWord, endWord);
    }
};
// @lc code=end

