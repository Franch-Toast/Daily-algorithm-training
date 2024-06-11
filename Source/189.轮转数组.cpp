/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
#include "vector"

using namespace std;

class Solution
{
public:
    void reverse(vector<int> &nums, int start, int end)
    {
        for (int i = start; i <= (start + end) / 2; i++)
        {
            swap(nums[i], nums[end + start - i]);
        }
    }
    void rotate(vector<int> &nums, int k)
    {

        int n = nums.size();
        k %= n; // 查看挪几轮
        if (k == 0)
            return; // 即原地不动
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = nums[(i + n - k) % n];
        }
        nums = ans;
        return;

        // int n = nums.size();
        // k %= n; // 查看挪几轮
    
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};
// @lc code=end
