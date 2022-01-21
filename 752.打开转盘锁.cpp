#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    vector<int> lock{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    unordered_map<string, int> MyMap;
    const string start = "0000";


    int openLock(vector<string>& deadends, string target) {
        queue<string> Q;
        Q.push(start);
        MyMap[start] = 0;
        //记录死亡数字
        for(auto x : deadends) {
            MyMap[x] = -1;
        }
        //BFS
        while(!Q.empty()) {
            string cur = Q.front();
            int step = MyMap[cur];
            if(cur == target) return step;
            //改变对应位置的转盘锁
            for(int flag = -1; flag < 2; flag += 2) {
                for(int i = 0; i < 4; i++) {
                    cur = Q.front();
                    if(cur[i] - '0' + flag == -1)   cur[i] = '9';
                    else    cur[i] = lock[(cur[i] - '0' + flag) % 10] + '0';
                    if(MyMap.count(cur) || MyMap[cur] == -1) continue;
                    Q.push(cur);
                    MyMap[cur] = step + 1;
                }
            }
            Q.pop();
        }
        return -1;
    }
};
// @lc code=end

