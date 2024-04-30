/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include "vector"
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n));

        dp[0][0] = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0) continue;
                else if(i == 0)
                {
                    dp[i][j] = dp[i][j-1];
                }                
                else if(j == 0)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }


        return dp[m-1][n-1];
    }
};
// @lc code=end

