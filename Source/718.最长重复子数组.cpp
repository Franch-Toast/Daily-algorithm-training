/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(m + 1,vector<int> (n + 1));

        // dp[i][j] ：长度为i的A，和长度为j的B，最长重复子数组长度为dp[i][j]
        // 注意！这里的 dp[i][j] 一定是以i-1和j-1结尾的子数组，不是中间的子数组，所以在遍历的过程中需要实时更新
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(nums1[i-1] == nums2[j-1]) 
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans,dp[i][j]);
                }
            }
        }

        return ans;

        }
};



// @lc code=end

