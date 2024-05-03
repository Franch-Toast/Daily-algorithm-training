/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include "string"
#include "vector"

using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        // dp[i][j] 代表word1[0-i]和word2[0-j]保持一致的最少操作数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[0][0] = 0; // 两者都为空时，最少操作数就是0

        // 边界填充
        for (int i = 0; i < m + 1; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j < n + 1; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (word1[i - 1] == word2[j - 1]) // 如果判断的这个字符本身就是相等的，那么在dp[i-1][j-1]上不需要进行操作
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end
