/*
 * @Author: Franch-Toast
 * @Date: 2024-01-02 10:58:59
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-02 11:41:51
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        long long count = 9;// 该数位段内的数字的数量
        int digit = 1;// 位数
        long long num = 1;// 数位段开始的数字

        while(n > count)// 确定n处在哪个位数段（digit）
        {
            n -= count;
            digit++;
            num *= 10;
            count = 9 * digit * num;
        }

        // 确定n处在digit位数段的哪个数字中
        num = (n-1) / digit + num;
        // 确定n在num数字中的哪个位上，变换成从左向右数的位数[1,digit]
        count = digit - (n-1) % digit;

        int ans = 0;
        while(count)
        {
            ans = num % 10;
            num /= 10;
            count--;
        }
        return ans;

    }
};
// @lc code=end

