/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include "vector"
#include "string"
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(),n = t.size();
        vector<vector<int>> dp(m + 1,vector<int> (n + 1));

        // dp[i][j] 表示长度为i和j且以其为结尾的s和t字符串（并非是索引）的最长字串的长度
        // 其实这样写有点奇怪，当然也可以是使用布尔值，而不计算，在下面也给出了
        
        /*
        如果使用bool的方法：
        */
        dp[0][0] = 1;
        for(int i = 0; i <= n; i++) dp[0][i] = 1;
        if(m == 0) return 1;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = i; j <= n; j++) 
            // 这里j直接从i开始，因为t字符串必须至少和s字符串一样长，不然s不能成为t的子串
            {
                // if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                // else
                //     dp[i][j] = dp[i][j - 1];

                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i-1][j-1] & 1;
                else
                    dp[i][j] = dp[i][j-1];
            }
        }

        // return dp[m][n] == m;// 计算长度时使用
        return dp[m][n];// 计算bool时使用
    }
};
// @lc code=end

