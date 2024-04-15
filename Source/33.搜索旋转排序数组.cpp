/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include "vector"
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target) // 中间点比目标值小，正常情况下应该向右边找
            {
                if (nums[mid] < nums[left] && nums[right] < target)
                    right = mid - 1; // 越过了旋转点，同时右界已经比目标值小了，说明要向前找
                else
                    left = mid + 1; // 如果没有越过旋转点或者右界比目标值，说明在右边找
            }
            else // 中间点比目标值大，正常情况下应该向左边找
            {
                if (nums[mid] > nums[right] && nums[left] > target)
                    left = mid + 1; // 没有越过旋转点，同时左界已经比目标值大了，说明要向后找
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

