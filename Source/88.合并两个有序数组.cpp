/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pointer1 = m-1,pointer2 = n-1;
        int i = m + n - 1;
        while(pointer1 >= 0 && pointer2 >= 0)
        {
            if(nums1[pointer1] >= nums2[pointer2]) nums1[i--] = nums1[pointer1--];
            else
                nums1[i--] = nums2[pointer2--];
        }

        while(pointer1 >= 0)
        {
            nums1[i--] = nums1[pointer1--];
        }
        while (pointer2 >= 0)
        {
            nums1[i--] = nums2[pointer2--];
        }

        return;
    }
};
// @lc code=end

