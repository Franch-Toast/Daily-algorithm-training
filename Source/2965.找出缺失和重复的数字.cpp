/*
 * @lc app=leetcode.cn id=2965 lang=cpp
 *
 * [2965] 找出缺失和重复的数字
 */

// @lc code=start
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> cnt(n * n + 1);
        for (auto &row : grid)
        {
            for (int x : row)
            {
                cnt[x]++;
            }
        }

        vector<int> ans(2);
        for (int i = 1; i <= n * n; i++)
        {
            if (cnt[i] == 2)
            {
                ans[0] = i; // 出现两次的数
            }
            else if (cnt[i] == 0)
            {
                ans[1] = i; // 出现零次的数
            }
        }
        return ans;
    }
};

              // @lc code=end
