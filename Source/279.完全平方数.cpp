/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include "vector"
#include "limits.h"
using namespace std;
class Solution
{
public:
    int dfs(vector<int> &dp, int i)
    {
        if (dp[i] != -1)
            return dp[i];

        int min_num = INT_MAX;
        for (int j = 1; j * j <= i; j++)
        {
            min_num = min(dfs(dp, i - j * j),min_num);
        }
        dp[i] = min_num + 1;
        return dp[i];
    }

    int numSquares(int n)
    {

        /* 使用递推的方法 */
        // vector<int> f(n + 1);
        // // 从前向后递推，f[i] 代表的意思为 何为i的完全平方数的最少数量，f[0] = 0;
        // for (int i = 1; i <= n; i++)
        // {
        //     int minn = INT_MAX;
        //     // 从 1 的完全平方数开始计算，一直到 i
        //     for (int j = 1; j * j <= i; j++)
        //     {
        //         minn = min(minn, f[i - j * j]); // 因为从小到大进行的计算，所以是没问题的，前面的已经计算过了
        //     }
        //     f[i] = minn + 1; // 在此前的基础上 + 1，因为要加上一个完全平方数
        // }
        // return f[n];

        /* 使用 递归 + 记忆化搜索的方法 */

        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;

        return dfs(dp, n);


    }
};

// @lc code=end
