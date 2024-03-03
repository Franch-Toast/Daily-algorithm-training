/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (left < nums.size() && nums[left] != 0)
            left++; // 找到第一个 0 的位置
        if (left == nums.size()) return;// 如果不存在 0 ，则直接返回
        while (right < nums.size() && left < nums.size())
        {
            if (nums[right] != 0 && left < right)
            {
                swap(nums[left], nums[right]); // 交换第一个非零和零
                left++;                        // 0 的位置一定是下一个
            }
            else
                right++; // 查找下一个非零位置
        }
        // return nums;
    }
};
// @lc code=end

