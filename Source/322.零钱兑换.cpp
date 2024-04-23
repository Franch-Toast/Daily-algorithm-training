/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include "vector"
#include "limits.h"
#include "algorithm"
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        sort(coins.begin(), coins.end());
        for (int i = 1; i < amount + 1; i++)
        {
            int min_num = INT_MAX;
            for (int j = 0; j < n && coins[j] <= i; j++)
            {
                if (dp[i - coins[j]] == -1) // 这种情况是没有方案不可行的
                    continue;
                min_num = min(dp[i - coins[j]], min_num);
            }
            if (min_num != INT_MAX)
                dp[i] = min_num + 1;
        }
        return dp[amount];
    }
};
// @lc code=end
