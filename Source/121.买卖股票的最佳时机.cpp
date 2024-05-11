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
        vector<vector<int>> dp(n,vector<int>(2));
        // dp[i][0] 表示第i天不持有股票的最大金额，dp[i][1] 表示第i天持有股票的最大金额

        dp[0][0] = 0;
        dp[0][1] = -prices[0]; // 第0天买股票

        for(int i = 1; i < n ; i++)
        {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]);
            // 注意不能用下面的这个语句，因为整个过程中只允许交易一次，如果这么写是可以交易多次的
            // dp[i][1] = max(dp[i-1][0]-prices[i],dp[i-1][1]);
            dp[i][1] = max(- prices[i], dp[i - 1][1]);
        }
        return dp[n-1][0];

        


        // int n = prices.size();
        // int history_min = prices[0]; // 记录历史最小值
        // int res = 0;
        // for (int i = 1; i < n; i++)
        // {
        //     res = max(res, prices[i] - history_min); // 前期的最小值，在这一天卖能赚多少钱
        //     history_min = min(history_min, prices[i]); // 历史最小值更新
        // }
        // return res;
    }
};
// @lc code=end

