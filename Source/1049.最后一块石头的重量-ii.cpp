// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1049.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include "vector"
#include "algorithm"
#include "numeric"
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int sum = accumulate(stones.begin(),stones.end(),0);
        int target = sum  / 2;

        int n = stones.size();
        vector<vector<int>> dp(target + 1,vector<int> (n+1,0));

        for(int i = 1; i <= n; i++)
        {
            int x = stones[i-1];
            for(int j = target; j >= 0; j--)
            {
                dp[j][i] = dp[j][i-1];
                if ( j >= x) dp[j][i] = max(dp[j][i],dp[j - x][i-1] + x);
            }
        }
        return sum - 2 * dp[target][n];
    }
};
// @lc code=end

