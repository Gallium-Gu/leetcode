// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include "commoncppproblem126.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;
    int size = INT_MAX;
    bool flag = false;

    void update(queue<string>& Q, unordered_map<string, string>& cur, 
    unordered_map<string, string>& other, unordered_set<string>& Set) {
        auto x = Q.front(); Q.pop();
        int n = x.size();
        
        for(int i = 0; i < n; i++) {
            for(int off = 0; off < 26; off++) {
                string a = x;
                a[i] = 'a' + off;

                if(!Set.count(a) || cur.count(a)) {
                    continue;
                }

                if(other.count(a)) {
                    cout << a << " ";
                    string y = x;
                    string b = a;
                    vector<string> ans;
                    while(cur.count(y)) {
                        ans.push_back(y);
                        y = cur[y];
                    }
                    reverse(ans.begin(), ans.end());
                    while(other.count(b)) {
                        ans.push_back(b);
                        b = other[b];
                    }
                    this->ans.push_back(ans);
                    if(ans.size() > size) {
                        flag = true;
                    }else{
                        size = ans.size();
                    }
                }
                Q.push(a);
                cur.emplace(a, x);
            }
        }
    }

    void BFS(unordered_set<string>& Set, string beginWord, string endWord) {
        //claration
        queue<string> Q1, Q2;
        unordered_map<string, string> M1, M2;
        //init
        Q1.push(beginWord); Q2.push(endWord);
        M1[beginWord] = "";  M2[endWord] = "";

        while(!Q1.empty() && !Q2.empty()) {
            vector<string> row;
            if(Q1.size() > Q2.size()) {
                update(Q2, M2, M1, Set);
            }else{
                update(Q1, M1, M2, Set);
            }

            if(flag) {
                return;
            }
        }
        return;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> Set(wordList.begin(), wordList.end());
        if(!Set.count(endWord))    return {};
        BFS(Set, beginWord, endWord);
        return ans;
    }
};
// @lc code=end

