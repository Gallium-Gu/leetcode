// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem665.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
    public boolean checkPossibility(int[] nums) {
        if (nums == null || nums.length <= 1) {
		return true;
	}
	int cnt = 0;
	for (int i = 1; i < nums.length && cnt < 2; i++) {
        if(cnt > 1){
            return false;
        }
		if (nums[i-1] <= nums[i]) {
			continue;
		}
		cnt++;
		if (i-2>=0 && nums[i-2] > nums[i]) {
			nums[i] = nums[i-1];
		}else {
			nums[i-1] = nums[i];
		}
	}
	return cnt <= 1;
    }
}
// @lc code=end

