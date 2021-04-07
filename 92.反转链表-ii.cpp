// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem92.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        // 设置 dummyNode 是这一类问题的一般做法
        ListNode *dummyNode = new ListNode(-1);
        ListNode *pre = head;
        for (int i = 0; i < left; i++) {
            pre = pre->next;
        }
        stack<ListNode*> preNode;
        for (int i = 0; i < (right - left) / 2; i++) {
            preNode.push(pre);
            pre = pre -> next;
        }
        if((right - left + 1) % 2 != 0) {
            pre = pre -> next;
        } 

        for(int i = 0; i < (right - left) / 2; i++) {
            swapNode(pre, preNode.top());
            preNode.pop();
            pre = pre -> next;
        }
        return dummyNode->next;
    }

    void swapNode(ListNode *node1, ListNode *node2) {
        ListNode *prev = node1 -> next;
        ListNode *last = node2 -> next;
        node1 -> next = last;
        node2 -> next = prev;
    }
};
// @lc code=end

