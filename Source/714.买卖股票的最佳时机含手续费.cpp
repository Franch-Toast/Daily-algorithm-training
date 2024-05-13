/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2));
        // dp[i][0] 表示第i天持有股票的最大金额
        // dp[i][1] 表示第i天未持有股票的最大金额
        dp[0][0] = -prices[0] - fee;

        for(int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] - prices[i] - fee);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] + prices[i]);
        }    

        return dp[n-1][1];
    }
};
// @lc code=end

