/*
 * @Author: Franch-Toast
 * @Date: 2024-01-26 10:06:06
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-26 11:37:04
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=2910 lang=cpp
 *
 * [2910] 合法分组的最少组数
 */

// @lc code=start
#include "vector"
#include "unordered_map"
#include "algorithm"

using namespace std;
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int> cnt;
        int n = nums.size();
        int start = 0;
        int min_length = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[i-1]) 
            {
                cnt[i - start]++; 
                min_length = min(min_length , i - start);
                start = i;
            }
        }
        cnt[n - start]++; 
        min_length = min(min_length , n - start);

        int ans = 0;
        for(;;min_length--)
        // 最小的长度开始向下枚举，因为最小的长度不一定能够满足分开的条件
        {
            for(auto [mem_cnt,num]:cnt)
            {
                if(mem_cnt % min_length > mem_cnt / min_length) 
                {
                    ans = 0;// 重新清零
                    break; // 不足一个组的数 不够被分配到前面的组里去 说明这个分组失败
                }
                else{
                    ans += (mem_cnt + min_length) / (min_length + 1) * num;
                    // 分成(min_length + 1)为一组，向上取整
                }
            }
            if(ans) return ans;
        }
        

    }
};
// @lc code=end

// int main()
// {
//     Solution apple;
//     vector<int> num = {10,10,10,3,1,1};
//     apple.minGroupsForValidAssignment(num);
//     return 1;
// }

//2910.合法分组的最少组数.cpp