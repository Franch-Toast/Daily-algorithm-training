// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem377.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include "vector"
using namespace std;
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // vector<int> dp(target + 1, 0);
        // dp[0] = 1;
        // for (int i = 0; i <= target; i++)
        // { // 遍历背包
        //     for (int j = 0; j < nums.size(); j++)
        //     { // 遍历物品
        //         if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]])
        //         {
        //             dp[i] += dp[i - nums[j]];
        //         }
        //     }
        // }
        // return dp[target];

        using ull = unsigned long long;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int j = 0; j <= target; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                //                    remove this part: use ull
                if (j < nums[i - 1] || dp[i - 1][j] > INT32_MAX - dp[n][j - nums[i - 1]])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[n][j - nums[i - 1]];
            }
        }

        return dp[n][target];
    }
};

