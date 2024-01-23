/*
 * @Author: Franch-Toast
 * @Date: 2024-01-23 09:43:17
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-23 10:22:19
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=2765 lang=cpp
 *
 * [2765] 最长交替子序列
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int temp = 1;
        for(int i = 0; i < n-1; )
        {
            if(nums[i+1] - nums[i] == 1) temp++;
            else{
                ans = max(ans,temp);
                temp = 1;
                i++;
                continue;
            }
            i++;
            if(i == n-1) break;
            if(nums[i+1] - nums[i] == -1) temp++;
            else{
                ans = max(ans,temp);
                temp = 1;
                continue;
            }
            i++;
        }
        ans = max(ans,temp);
        return ans == 1 ? -1 : ans;


    }
};
// @lc code=end

// int main()
// {
//     Solution apple;
//     vector<int> test = {2,3,4,3,4};
//     apple.alternatingSubarray(test);
//     return 1;
// }
