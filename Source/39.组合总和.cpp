/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include "vector"
#include "algorithm"

using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<int> candidates, int target, int pos)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        for (int i = pos; i < candidates.size(); i++)
        {
            if (target - candidates[i] >= 0)
            {
                path.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i);
                path.pop_back();
            }
            else
                return;
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
};
// @lc code=end
