/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start

#include "vector"
#include "numeric"
#include "algorithm"
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1) // 和为奇数，不可能平分成两个相等的整数
        {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target)// 如果最大的值已经比目标值大了，那么不可能分成两个相等的子集
        {
            return false;
        }
        // dp[i][j] 表示 背包容量为j，考虑从第0个到第i个元素是否能成功
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true; // 背包容量为0时，一定能找到，就是不放i索引数值
        }
        dp[0][nums[0]] = true; // 背包容量为 nums[0] 时，放0索引数值即可
        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            // 遍历背包容量
            for (int j = 1; j <= target; j++)
            {
                if (j >= num) // 该容量可以考虑该i索引的数值
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num]; // 如果考虑到前面的（i-1）能成功或考虑到i-1，背包容量为 j-num能够成功就能成功
                }
                else // 该i索引的数值已经超过容量了
                {
                    dp[i][j] = dp[i - 1][j]; // 如果考虑到前面的能够实现，那么考虑到i一定也能实现
                }
            }
        }
        return dp[n - 1][target];
    }
};
// @lc code=end
