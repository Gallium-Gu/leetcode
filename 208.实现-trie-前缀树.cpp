// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem208.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    class TreeNode {
        public:
            char word;
            unordered_map<char, TreeNode*> next;
            TreeNode() : word(), isEnd(false) {};
            TreeNode(char x) : word(x), isEnd(false) {};
            bool isEnd;
    };

    TreeNode* head;
    //生成以xx结尾的前缀树
    TreeNode* generate(string word) {
        TreeNode* head = new TreeNode(word[0]);
        TreeNode* prev = head;
        for(int i = 1; i < word.size(); i++) {
            TreeNode* cur = new TreeNode(word[i]);
            (head -> next)[word[i]] = cur;
            head = cur; 
        }
        head -> isEnd = true;
        return prev;
    }

    /** Initialize your data structure here. */
    Trie() {
        head = new TreeNode('t');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode* cur = head;
        int i = 0;
        for(i = 0; i < word.length(); i++) {
            if(!(cur -> next).count(word[i])) {
                break;
            }
            cur = (cur -> next).find(word[i]) -> second;
        }
        if(i == word.length()) {
            cur -> isEnd = true;
        }else{
            (cur -> next)[word[i]] = generate(word.substr(i, word.size() - i)); 
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode* cur = head;
        TreeNode* prev;
        int i = 0;
        while(cur != NULL && i < word.size()) {
            if((cur -> next).count(word[i]))
            {   
                cur = (cur -> next).find(word[i]) -> second;
                i++;
            }else{
                return false;
            }
        }
        if(cur -> isEnd) {
            return true;
        }else{
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode* cur = head;
        int i = 0;
        while(cur != NULL && i < prefix.size()) {
            if((cur -> next).count(prefix[i]))
            {   
                cur = (cur -> next).find(prefix[i]) -> second;
                i++;
            }else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

