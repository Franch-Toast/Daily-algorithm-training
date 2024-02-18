/*
 * @Author: Franch-Toast
 * @Date: 2024-02-18 12:07:56
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-02-18 12:19:42
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include "vector"
#include "unordered_map"

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;
        unordered_map<int,int> hash;
        for(int i = 0; i < nums.size(); i++)
        {
            if(hash.count(target - nums[i]))
            {
                return {i,hash[target - nums[i]]};
            }
            hash[nums[i]] = i;
        }
        return {};


    }
};
// @lc code=end

