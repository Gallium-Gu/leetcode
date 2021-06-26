#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

// @lc code=start
class Solution {
public:
//如果一个数里面只有2,5,6,9,0,1,8就是有效数
//有效数中含有2,5,6,9就是好数
//[0,9]有7个有效数,有3个仅是有效数
//[0,99]有7*7个有效数，有3*3仅是有效数
    int rotatedDigits(int n) {
        string word = to_string(n);
        int valid = 1;
        int Ungood = 1;
        for(int i = 0; i < word.size 90 - 1; i++){
            valid *= 7;
            Ungood *= 3;
        }
        char x = *(word.begin());
        if(x >= '8') Ungood *= 
    }
};
// @lc code=end

