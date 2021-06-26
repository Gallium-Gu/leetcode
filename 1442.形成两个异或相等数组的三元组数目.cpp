#include <vector>
/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */

// @lc code=start
class Solution {
    // class Trie {
    //     Trie left = nullptr;
    //     Trie right = nullptr;

    //     void add(int num){
    //         root = this;
    //         for(int i = 30; i >= 0; i++) {
    //             int bit = (num >> i) & 1
    //             if(bit == 1) {
    //                 if(!(root -> right)) {
    //                     root -> right = Tire();
    //                 }
    //                 root = root -> right;
    //             }else{
    //                 if(!(root -> left)) {
    //                     root -> left = Tire();
    //                 }
    //                 root = root -> left;
    //             }
    //         }
    //     }

    //     bool checkNum(int num){
    //         root = this;
    //         int x = 0;
    //         for(int i = 30; i >= 0; i++) {
    //             int bit = (num >> i) & 1
    //             if(bit == 1) {
    //                 if(!(root -> right)) {
    //                     return false;
    //                 }
    //                 root = root -> right;
    //             }else{
    //                 if(!(root -> left)) {
    //                     return false;
    //                 }
    //                 root = root -> left;
    //             }
    //         }
    //         return true;
    //     }
    // }
public:
    int countTriplets(vector<int>& arr) {
        // int n = arr.size();
        // Trie root = new Trie();
        // for(int i = 1; i < n; i++) {
        //     root.add(arr[i - 1]);
        //     if()
        // }

        
    }
};
// @lc code=end

