/*
 * @lc app=leetcode.cn id=2859 lang=cpp
 *
 * [2859] 计算 K 置位下标对应元素的和
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    bool get_cnt(int num,int k)
    {
        int cnt = 0;
        while(num && cnt <= k)
        {
            cnt += (num % 2);// 不需要用判断语句
            num /= 2;
        } 
        if(cnt != k) return 0;
        return 1;
    }


    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(get_cnt(i,k)) res += nums[i];
        }
        return res;
    }
};
// @lc code=end

