/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        set<int> s;
        s.insert(A[0]);
        for(int i = 2; i < A.size(); ++i)
        {
            if(s.lower_bound(A[i]+1) != s.end())
            {   //前面存在比 A[i] 大的数
                return false;
            }
            s.insert(A[i-1]);
        }
        return true;
    }
};
// @lc code=end

