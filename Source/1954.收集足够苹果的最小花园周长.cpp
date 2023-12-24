/*
 * @Author: Franch-Toast
 * @Date: 2023-12-24 21:46:16
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2023-12-24 22:23:05
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=1954 lang=cpp
 *
 * [1954] 收集足够苹果的最小花园周长
 */

// @lc code=start
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {

        int left = 1,right = 100000;
        int ans = 1;
        while(left <= right)
        {
            long long side = left + (right - left) / 2;
            long long apples = (1 + side) * (side) * (2 * side + 1) * 2;
            
            if(apples >= neededApples) 
            {
                right = side - 1;
                ans = side;
            }
            else left = side + 1;
        }
        return ans * 8;
    }
};
// @lc code=end

