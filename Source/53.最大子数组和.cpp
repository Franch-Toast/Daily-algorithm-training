// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem53.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include "vector"
#include "algorithm"
using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         // 使用DP
//         int n = nums.size();

//         for(int i = 1;i < n;i++)
//         {
//             nums[i] = max(nums[i-1] + nums[i],nums[i]);
//             // 计算连续和如果加上当前这个数不如这个数字本身，那不如从这个数字本身开始叠加
//         }
//         // 遍历完后只要找到过程中的最大的数即可
//         return *max_element(nums.begin(),nums.end());

//     }
// };
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        int min_pre_sum = 0;
        int pre_sum = 0;
        for (int x : nums)
        {
            pre_sum += x;                            // 当前的前缀和
            /* 注意这里一定是先减去前缀和的最小值，然后再更新，否则可能会出现子数组为空的情况 */
            ans = max(ans, pre_sum - min_pre_sum);   // 减去前缀和的最小值
            min_pre_sum = min(min_pre_sum, pre_sum); // 维护前缀和的最小值
        }
        return ans;
    }
};

// @lc code=end
