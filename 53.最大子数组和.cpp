/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 使用DP
        int n = nums.size();

        for(int i = 1;i < n;i++)
        {
            nums[i] = max(nums[i-1] + nums[i],nums[i]);
            // 计算连续和如果加上当前这个数不如这个数字本身，那不如从这个数字本身开始叠加
        }
        // 遍历完后只要找到过程中的最大的数即可
        return *max_element(nums.begin(),nums.end());

    }
};
// @lc code=end

