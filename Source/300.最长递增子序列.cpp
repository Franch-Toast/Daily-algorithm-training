/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include "string"
#include "vector"
#include "unordered_set"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        // dp[i] 表明以i为最后一个元素的子序列的最长长度
        vector<int> dp(n,1);
        for(int i = 0; i < n; i++)
        {
            for(int j = i-1 ; j >= 0; j--)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[j] + 1,dp[i]); 
                }
            }
            ans = max(ans,dp[i]);
        }

        return ans;
    }
};
// @lc code=end

