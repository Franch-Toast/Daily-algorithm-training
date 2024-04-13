/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> cur;
    vector<vector<int>> permute(vector<int> &nums)
    {
        back(nums);
        return ans;
    }
    
    void back(vector<int> &nums)
    {
        if (cur.size() == nums.size()) // 元素满了
            ans.push_back(cur);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 11) // 该数没有被用过，即没做标记
            {
                int temp = nums[i];
                nums[i] = 11; // 标记该数，表明被用过
                cur.push_back(temp);
                back(nums);
                cur.pop_back(); // 弹出，回溯
                nums[i] = temp; // 还原数组
            }
        }
        return;
    }
};
// @lc code=end
