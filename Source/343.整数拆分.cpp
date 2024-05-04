/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include "vector"
using namespace std;
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1);

        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i < n + 1; i++)
        {
            for(int j = i/2; j >= 1; j--)
            {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }

        }
        return dp[n];
    }
};
// @lc code=end
