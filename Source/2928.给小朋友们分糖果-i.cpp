/*
 * @lc app=leetcode.cn id=2928 lang=cpp
 *
 * [2928] 给小朋友们分糖果 I
 */

// @lc code=start
class Solution
{
public:
    int distributeCandies(int n, int limit)
    {
        int ans = 0;
        for (int i = 0; i <= min(limit, n); i++)
        {
            if (n - i > 2 * limit)
            {
                continue;
            }
            // 此时 其中一个人至少要分 max(0, n - i - limit) 个才能使另一个人不超limit，但是自己又不能超limit
            ans += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return ans;
    }
};
              // @lc code=end
