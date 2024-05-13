/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        int length = 1;

        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > nums[i-1]) length++;
            else
            {
                ans = max(ans, length);
                length = 1;
            }
        }
        ans = max(ans, length);
        return ans;
    }
};
// @lc code=end

