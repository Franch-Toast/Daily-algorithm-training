/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution
{
public:
    vector<int> distributeCandies(int candies, int n)
    {
        vector<int> ans(n);
        for (int i = 1; candies > 0; i++)
        {
            ans[(i - 1) % n] += min(i, candies);
            candies -= i;
        }
        return ans;
    }
};

              // @lc code=end
