#include <queue>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=1481 lang=cpp
 *
 * [1481] 不同整数的最少数目
 */

// @lc code=start
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mymap;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            mymap[arr[i]]++;
        }

        for(int i = 0; i < n; i++) {
            
        }
    }
};
// @lc code=end

