/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[0] = 1;
        for(int i = 2; i < n + 1; i++)
        {
            for(int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i-1-j]; 
        }
        return dp[n];

    }
};
// @lc code=end

