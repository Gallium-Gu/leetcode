#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
    int getInt(const string s) {
        for(int i = 0; i < s.size(); i++) {
            if(i == 'e' || i == 'E' || i == '.') {
                return i;
            }
        }
        return s.size();
    }

    bool isInt(const string s) {
        if(s[0] == '+' || s[0] == '-') {
            s = s.substr(1, s.size());
        }
        if(s.empty()) {
            return false;
        }
        for(auto i : s) {
            if(isdigit(i)) {
                return false;
            }
        }
        return true;
    }

    bool isNumber(string s) {
        int i = 0;
        while(i < s.size()) {
            int index = getInt(s.substr(i, s.size()))
            if(!isInt(i, index)) {
                return false;
            }
            i = index;
        }
        return true;
    }
};
// @lc code=end

