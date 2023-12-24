/*
 * @Author: Franch-Toast
 * @Date: 2023-12-24 22:26:08
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2023-12-24 23:05:06
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include "vector"

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int left = 0,right = nums.size() - 1;
        int pos1 = 0,pos2 = 0;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target)
            {
                pos1 = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        if(nums[pos1] != target) return {-1,-1};
        right = nums.size() - 1;
        left = pos1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target)
                right = mid - 1;
            else 
            {
                left = mid + 1;
                pos2 = mid;
            }
        }
        return {pos1,pos2};


    }
};


// int main()
// {
//     Solution apple;
//     vector<int> test = {2,2};
//     apple.searchRange(test,3);
//     return 0;
// }
// @lc code=end

