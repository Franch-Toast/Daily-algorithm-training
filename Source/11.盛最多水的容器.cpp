/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0; // 记录当前可以存的最大水量

        int left = 0, right = height.size() - 1;
        while(left != right)
        {
            int cur = (right - left) * min(height[left],height[right]);
            if(cur > ans)
            {
                ans = cur;
            }
            if(height[left] < height[right]) left++;
            else right--;
        }
        return ans;
    }
};
// @lc code=end

