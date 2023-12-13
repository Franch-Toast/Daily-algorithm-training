/*
 * @lc app=leetcode.cn id=2367 lang=cpp
 *
 * [2367] 算术三元组的数目
 */

// @lc code=start
#include "vector"

using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        // 三指针，不断递进
        int left = 0,mid = 1,right = 2;
        int n = nums.size();
        int ans = 0;
        while(left <= n-3 && mid <= n-2 && right <= n-1)
        {
            while(mid <= n-2 && nums[mid] - nums[left] < diff) mid++;
            if(mid > n-2 || nums[mid] - nums[left] > diff) 
            {
                left++;
                continue;
            }
            while(right <= n-1 && nums[right] - nums[mid] < diff) right++;
            if(right > n-1 || nums[right] - nums[mid] > diff) 
            {
                left++;
                continue;
            }
            ans++;
            left++;

        }
        return ans;
    }
};
// @lc code=end

