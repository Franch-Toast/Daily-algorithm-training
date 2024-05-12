/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (4));
        /*
        dp[i][0] 第i天持有股票的最大金额
        dp[i][1] 第i天卖出股票的最大金额
        dp[i][2] 第i天前卖出股票目前未持有的最大金额
        dp[i][3] 第i天为冷冻期的最大金额
        */

        dp[0][0] = -prices[0];

        for(int i = 1; i < n; i++)
        {
            dp[i][0] = max(max(dp[i-1][0],dp[i-1][3] - prices[i]),dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][1],dp[i-1][2]);
            dp[i][3] = dp[i-1][1];
        }

        return max(max(dp[n-1][3],dp[n-1][1]),dp[n-1][2]);
    }
};
// @lc code=end

