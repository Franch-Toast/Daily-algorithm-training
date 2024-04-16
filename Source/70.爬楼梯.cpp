/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int ans = 0;
        int prepre = 1;
        int pre = 1;
        int cur = 1; // 为了防止只有一节台阶不需要进入循环，所以直接令cur = 1
        for (int i = 2; i <= n; i++)
        {
            cur = prepre + pre;
            prepre = pre;
            pre = cur;
        }
        return cur;
    }
};
// @lc code=end

