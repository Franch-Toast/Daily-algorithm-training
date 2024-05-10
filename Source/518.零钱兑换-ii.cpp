/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include "string"
#include "vector"
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> f(n + 1, vector<int>(amount + 1));
        f[0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int c = 0; c <= amount; c++)
            {
                f[i + 1][c] = f[i][c];
                if (c >= coins[i])
                {
                    f[i + 1][c] += f[i + 1][c - coins[i]];
                }
            }
        }
        return f[n][amount];
    }
};

// @lc code=end
