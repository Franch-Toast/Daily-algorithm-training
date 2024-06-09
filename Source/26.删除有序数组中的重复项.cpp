// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem26.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int pos = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        while(left < n)
        {
            while (right < n && nums[left] == nums[right])
                right++;
            nums[pos++] = nums[left];
            left = right;
        }
        return pos;
    }
};
// @lc code=end
