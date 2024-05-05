/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include "vector"
#include "numeric"
#include "algorithm"

using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > sum) return 0;
        if ((sum + target) % 2)
            return 0; // 不可能找到
        int t = (sum + target) / 2;
        vector<vector<int>> dp(n, vector<int>(t + 1));

        
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        if(t >= nums[0]) dp[0][nums[0]] += 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < t + 1; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i]) dp[i][j] += dp[i-1][j - nums[i]];
            }
        }


        return dp[n-1][t];
    }
};
// @lc code=end
