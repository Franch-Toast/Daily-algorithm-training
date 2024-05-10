// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem279.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include "vector"
#include "limits.h"
#include "cmath"
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= (int)sqrt(i); j++){

                dp[i] = min(dp[i-j*j] + 1,dp[i]);

            }

        }

        return dp[n];

    }
};

// @lc code=end
