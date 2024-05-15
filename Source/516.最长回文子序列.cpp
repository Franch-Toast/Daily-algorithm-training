/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include "string"
#include "vector"

using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (i >= j)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2; // 比较巧妙，当 i+1 > j-1 时，因为此前不会遍历到，所以会是初始值0
                }
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];    

    }
};
// @lc code=end

