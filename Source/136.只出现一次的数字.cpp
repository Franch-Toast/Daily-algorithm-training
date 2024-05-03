/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include "vector"

#include "unordered_set"

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // 方法一
        int res = 0;
        for(int num : nums)
        {
            res ^= num;
        }

        return res;

        // 方法二
        unordered_set<int> set;
        for(int num : nums)
        {
            if(set.count(num)) set.erase(num);
            else set.insert(num);
        }
        return *set.begin();

    }
};
// @lc code=end

