/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include "vector"

using namespace std;
// 注意注释中的情况二情况三，以及把198.打家劫舍的代码抽离出来了
class Solution
{
public:
    /* 本题的思想在于：既然首尾成环会互相制约，那么我分类讨论即可
    考虑【0,n-2】，即最后一个房子不考虑，一定不偷，这个时候对0房子就没有制约了，变成了普通打家劫舍
    考虑【1,n-1】，即第一个房子不考虑，一定不偷，这个时候对n-1房子就没有制约了，变成了普通打家劫舍
    再把两个情况求一个最大值即可

    第一种情况和第二种情况其实是相互补充的，比如第一种情况子n-1房子一定不偷
    在第二种情况中也不是说n-1房子一定偷，而是交给转移方程来判断，所以两者之间其实是有部分重叠的
     */


    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int result1 = robRange(nums, 0, nums.size() - 2); // 情况二
        int result2 = robRange(nums, 1, nums.size() - 1); // 情况三
        return max(result1, result2);
    }
    // 198.打家劫舍的逻辑
    int robRange(vector<int> &nums, int start, int end)
    {
        if (end == start)
            return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};
// @lc code=end

