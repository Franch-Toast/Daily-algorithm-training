/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); ++i)
        {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};

// @lc code=end
