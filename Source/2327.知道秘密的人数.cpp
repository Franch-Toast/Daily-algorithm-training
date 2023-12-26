/*
 * @lc app=leetcode.cn id=2327 lang=cpp
 *
 * [2327] 知道秘密的人数
 */

// @lc code=start
#include <string.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(i + delay >= n) cnt = (cnt + dp[i]) % mod;
            for(int j = i + delay ; j < min(i + forget , n); j++)
            {
                dp[j] = (dp[j] + dp[i]) % mod;
            } 
        }
        return (dp[n-1] + cnt)%mod;

    }
};
// @lc code=end

