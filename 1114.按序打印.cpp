#include <stdlib.h>
/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */

// @lc code=start
class Foo {
    int falg = 0;
public:
    Foo() {
        falg = 0;
    }

    void first(function<void()> printFirst) {
        falg = 1;
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        falg = 0;
    }

    void second(function<void()> printSecond) {
        if(falg == 0) {
            _sleep(1);
        } 
        falg = 1;
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        falg = 0;
    }

    void third(function<void()> printThird) {
        if(falg == 0) {
            _sleep(1);
        } 
        falg = 1;
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        falg = 0;
    }
};
// @lc code=end

