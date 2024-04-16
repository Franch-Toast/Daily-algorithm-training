/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int history_min = prices[0]; // 记录历史最小值
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            res = max(res, prices[i] - history_min); // 前期的最小值，在这一天卖能赚多少钱
            history_min = min(history_min, prices[i]); // 历史最小值更新
        }
        return res;
    }
};
// @lc code=end

