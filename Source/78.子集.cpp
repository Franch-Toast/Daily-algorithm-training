/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int> &nums, int start)
    {
        // if (start >= nums.size()) // 其实可以不要，因为这种情况不会进入循环
        //     return;

        /* 从start开始，前面的元素不考虑了，因为在之前已经考虑过了 */
        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            ans.push_back(path);
            dfs(nums, i + 1); 
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(nums, 0);
        ans.push_back({}); // 先将空集放进答案
        return ans;
    }
};
// @lc code=end

