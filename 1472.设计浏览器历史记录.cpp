#include <vector>
#include <string>

using namespace std;
/*
 * @lc app=leetcode.cn id=1472 lang=cpp
 *
 * [1472] 设计浏览器历史记录
 */

// @lc code=start
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        urls.resize(5000);
        urls[0] = homepage;
        current = 0;
        size = 1;
    }

    void visit(string url) {
        urls[++current] = url;
        size = current + 1;
    }

    string back(int steps) {
        current = current > steps ? current - steps : 0;
        return urls[current];
    }

    string forward(int steps) {
        current = (current + steps) >= size ? size - 1 : (current + steps);
        return urls[current];
    }

private:
    vector<string> urls;
    int current;
    int size;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

