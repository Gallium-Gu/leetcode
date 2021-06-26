#include <alogrothim>
#include <vector>
#include <numeric>
using namespace std;
/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0;
        while (left <= n)
        {   
            int mid = left + (n - left) / 2;
            int x = guess(mid);
            switch (x)
            {
            case 1:
                left = mid + 1;
                break;

            case -1:
                n = mid - 1;
                break;
            
            default:
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end

