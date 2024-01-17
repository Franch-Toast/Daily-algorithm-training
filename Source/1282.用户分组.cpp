/*
 * @Author: Franch-Toast
 * @Date: 2024-01-17 20:11:54
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-17 20:40:04
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> cnt(n+1);
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            cnt[groupSizes[i]].push_back(i);
            // 遍历一遍放到对应哈希表数组中，记录所在人数组数的数字的位置
        }

        for(int i = 1; i < n+1; i++)
        {
            if(cnt[i].empty()) continue;// 表示 该组别没有人在
            
            for(int start = 0; start < cnt[i].size()/i; start++)// 计算该组别要分多少组
            {
                vector<int> temp;
                for(int j = 0; j < i; j++)// 将每个组填充
                {
                    temp.push_back(cnt[i][start * i + j]);
                }
                ans.push_back(temp);
            }
            
        }
        return ans;

    }
};
// @lc code=end

