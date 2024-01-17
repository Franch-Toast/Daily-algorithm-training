/*
 * @Author: Franch-Toast
 * @Date: 2024-01-17 17:25:39
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-17 20:02:09
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=2744 lang=cpp
 *
 * [2744] 最大字符串配对数目
 */

// @lc code=start
#include "unordered_set"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<int> show;
        int cnt = 0;
        for(string str:words)
        {
            int origin = (1 << (str[0] - 'a')) + (1 << (str[1] - 'a'));
            int reverse = (1 << (str[1] - 'a')) + (1 << (str[0] - 'a'));
            
            // reverse(str.begin(), str.end()); 反转字符串可以直接通过这个api
            if(show.count(origin)) cnt++;
            else show.insert(reverse);
        }
        return cnt;
    }
};
// @lc code=end

