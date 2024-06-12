/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> index;
        for(int i = 0; i < n; i++)
        {
            if(!index.count(nums[i]))
                index[nums[i]] = i;
            else{
                if(i - index[nums[i]] <= k) return 1;
                index[nums[i]] = i;
            }
        }
        return 0;
    }
};
// @lc code=end

