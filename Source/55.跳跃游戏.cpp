/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include "vector"
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int before_far = 0;
        int far = nums[0];
        int n = nums.size();

        while(far < n - 1)
        {
            int temp = 0;
            for(int i = before_far + 1; i<= far;i++)
            {
                temp = max(temp,i + nums[i]);
            }
            if(temp <= far) return 0;
            before_far = far;
            far = temp;
        }

        return 1;
    }
};
// @lc code=end

