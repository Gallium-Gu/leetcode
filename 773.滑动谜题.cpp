/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
    class Node{
        public:
            //当前棋盘状态
            string status;
            //零点位置
            int x;
            int y;
            Node(int px, int py, string curStatus) : status(curStatus), x(px), y(py) {}
    };
public:
    //hash存储所有到当前状况的最小步数, board -> cur
    unordered_map<string, int> hash;
    const vector<vector<int>> dicts{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    //目标矩阵
    vector<vector<int>> ans = {{1, 2, 3}, {4, 5, 0}};

    bool inArea(int x, int y){
        return x < 2 && x >= 0 && y < 3 && y >= 0;
    }

    //当前状态hash值
    // int getHash(const string board) const{
    //     int hash = 0;
    //     for(int i = 0; i < board.size(); i++) {
    //         hash += (board[i] - '0') * board.size() * i;
    //     }
    //     return hash;
    // }

    int getIndex(const int x, const int y) {
        return x * 3 + y;
    }
    //x, y为零的位置,返回值为到达ans的步数, bushu记录 board -> curboard
    //bfs队列
    int bfs(int x, int y, string status){
        //b里面放的是当前状态状态
        queue<Node> Qhash;
        Qhash.push(Node(x, y, status));
        //初始状态
        hash[status] = 0;
        while(!Qhash.empty()) {
            //获取头的hash
            Node curNode = Qhash.front();
            Qhash.pop();
            //到达当前需要步数
            int step = hash[curNode.status];
            //遍历到了
            if(curNode.status == "123450") return step;
            
            //获取零点位置(x, y)
            for(auto dict : dicts){
                string curStatus = curNode.status;
                int px = curNode.x + dict[0];
                int py = curNode.y + dict[1];
                if(inArea(px, py)) {
                    //交换零点和px,py
                    swap(curStatus[getIndex(curNode.x, curNode.y)], curStatus[getIndex(px, py)]);
                    //已经有了当前状态
                    if(hash.count(curStatus)) continue;
                    Qhash.push(Node(px, py, curStatus));
                    hash[curStatus] = step + 1;
                }
            } 
        }
        return hash.count("123450") ? hash["123450"] : -1;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        //memset(hash, INT_MAX - 1, sizeof(hash));
        int x, y;
        string status;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++){
                status += board[i][j] + '0';
                if(board[i][j] == 0) {
                    x = i; y = j;
                }
            }
        }
        return bfs(x, y, status);
    }
};


// @lc code=end

