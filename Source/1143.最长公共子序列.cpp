/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include "string"
#include "vector"

using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();

        // dp[i][j] 表示 text1[0-i]和text2[0-j]字符串的最大公共子串
        vector<vector<int>> dp(m + 1,vector<int>(n + 1));

        for(int i = 1; i < m + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

