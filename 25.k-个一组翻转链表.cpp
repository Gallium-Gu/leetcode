// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem25.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* nextCurr = curr;
            for(int i = 0; i < k; i++){
                nextCurr = nextCurr -> next;
            }
            reverseList(curr, nextCurr);
            curr = nextCurr;
            curr = curr -> next;
        }
        return curr;
    }

    ListNode* reverseList(ListNode* head,ListNode* nexthead) {
        ListNode* prev = nexthead; //前指针节点
        ListNode* curr = head; //当前指针节点
        //每次循环，都将当前节点指向它前面的节点，然后当前节点和前节点后移
        while (curr != NULL) {
            ListNode* nextTemp = curr->next; //临时节点，暂存当前节点的下一节点，用于后移
            curr->next = prev; //将当前节点指向它前面的节点
            prev = curr; //前指针后移
            curr = nextTemp; //当前指针后移
        }
        return prev;
    } 
};
// @lc code=end

