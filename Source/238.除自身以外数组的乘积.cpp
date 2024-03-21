/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);

        /* 首先计算左边的 */
        for (int i = 1; i < n; i++)
        {
            // 每一个元素的左边应该等于上一个元素的左边乘上上一个元素（之前没有乘自己）
            ans[i] = ans[i - 1] * nums[i - 1]; 
        }
        int temp = 1;
        /* 计算右边的 */
        for (int i = n - 2; i >= 0; i--)
        {
            temp *= nums[i + 1];
            // 每一个元素的右边应该等于下一个元素的右边乘上下一个元素（之前没有乘自己）
            ans[i] *= temp;
        }
        return ans;
    }
};
// @lc code=end
