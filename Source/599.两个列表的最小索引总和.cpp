/*
 * @Author: Franch-Toast
 * @Date: 2024-01-21 13:22:07
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-21 13:42:44
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> show;
        vector<string> ans;
        int min_index = INT_MAX;
        for(int i = 0; i < list1.size(); i++) show[list1[i]] = i;
        for(int i = 0; i < list2.size(); i++)
        {
            if(show.count(list2[i]))
            {
                if(i + show[list2[i]] == min_index) ans.push_back(list2[i]);
                else if(i + show[list2[i]] < min_index)
                {
                    min_index = i + show[list2[i]];
                    ans.clear();
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

