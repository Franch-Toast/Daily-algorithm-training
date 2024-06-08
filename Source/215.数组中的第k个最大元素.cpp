/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include "vector"
#include "algorithm"
using namespace std;
class Solution
{
public:
    int quickSelect(vector<int> &nums, int k)
    {
        // 随机选择基准数
        int pivot = nums[rand() % nums.size()];
        // 将大于、小于、等于 pivot 的元素划分至 big, small, equal 中
        vector<int> big, equal, small;
        for (int num : nums)
        {
            if (num > pivot)
                big.push_back(num);
            else if (num < pivot)
                small.push_back(num);
            else
                equal.push_back(num);
        }
        // 第 k 大元素在 big 中，递归划分
        if (k <= big.size())
            return quickSelect(big, k);
        // 第 k 大元素在 small 中，递归划分
        if (nums.size() - small.size() < k)
            return quickSelect(small, k - nums.size() + small.size());
        // 第 k 大元素在 equal 中，直接返回 pivot
        return pivot;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        // 快排
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];

        // 三路选择排序
        int ans = quickSelect(nums,k);
        return ans;
    }
};
// @lc code=end
