/*
 * @Author: Franch-Toast
 * @Date: 2024-01-28 09:48:01
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-28 10:18:01
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> repeat;
        vector<string> ans;
        if(s.size() <= 10) return ans;

        for(int i = 0; i <= s.size() - 10; i++)
        {
            string cur = s.substr(i,10);
            if(repeat[cur] == 1)
            {
                ans.push_back(cur);
                repeat[cur]++;
            }
            else repeat[cur]++;
        }
        return ans;
    }
};
// @lc code=end

