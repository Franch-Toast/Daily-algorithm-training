/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include "vector"

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // dp[i] 表示考虑到第 i 间房子最大金额
        vector<int> dp(n+1);
        dp[1] = nums[0];

        for(int i = 2; i <= n; i++)
        {
            // 考虑到第i间房子的最大金额 = max(不偷第i间房（即考虑到i-1），偷第i间房)
            dp[i] = max(dp[i-1],dp[i-2] + nums[i-1]);
        }

        return dp[n];

    }

    // // 表示 从 0 - n 可以获取到的最大的金额
    // int dfs(vector<int> nums,vector<int> &dp, int n)
    // {
    //     if(n < 0) return 0;// 表示没有房子，直接返回0
    //     if(dp[n] != -1) return dp[n];
    //     // 在返回之前记录，防止重复计算
    //     dp[n] = max(dfs(nums, dp, n - 1), dfs(nums, dp, n - 2) + nums[n]);
    //     return dp[n];
    // }

    // int rob(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     vector<int> dp(n,-1);// 初始化为一个不可能的值，用来标记此前是否计算过

    //     return dfs(nums,dp,n - 1);
    // }
};
// @lc code=end
