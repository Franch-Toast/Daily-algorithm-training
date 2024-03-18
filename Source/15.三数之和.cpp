/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include "vector"
#include "algorithm"
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] > 0) // 一旦这个值大于0，则直接结束，因为后面的值相加一定大于0了
                break;
            int l = i + 1, r = len - 1;
            while (l < r) // 在 [l,r] 间找
            {
                if (nums[l] + nums[r] == -nums[i])
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    // 边界向中间收缩，两边同时移动，因为这两个值不能用了
                    ++l;
                    --r;

                    while (l < r && nums[l] == nums[l - 1]) // 左边界向中间收缩，如果数值相同，则也不能用，否则会重复
                        ++l;
                    while (l < r && nums[r] == nums[r + 1]) // 右边界向中间收缩，如果数值相同，则也不能用，否则会重复
                        --r;
                }
                else if (nums[l] + nums[r] > -nums[i])
                {
                    --r;
                }
                else
                {
                    ++l;
                }
            }
            while (i + 1 < len && nums[i + 1] == nums[i]) // 最左端元素向右移动，要给预留两个位子，同时不能重复参与
                ++i;
        }

        return ans;
    }
};
// @lc code=end
