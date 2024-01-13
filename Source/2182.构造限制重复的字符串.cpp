/*
 * @Author: Franch-Toast
 * @Date: 2024-01-13 13:37:59
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-13 14:47:26
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=2182 lang=cpp
 *
 * [2182] 构造限制重复的字符串
 */

// @lc code=start
#include "string"
#include "vector"

using namespace std;
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cha(26);
        for(char str:s)
        {
            cha[str-'a']++;
        }
        string ans = "";
        int index = 25;
        while(1)
        {
            while(index >= 0 && cha[index] == 0) index--;// 找到出现的字符串
            if(index < 0) break;
            for(int i = 0;i < min(cha[index],repeatLimit); i++)// 填充这个数字最多的情况
            {
                ans += ('a' + index);
            }
            if(cha[index] <= repeatLimit) cha[index] = 0;
            else
            {
                cha[index] -= repeatLimit;
                int temp = index - 1;
                while(temp >= 0 && cha[temp] == 0) temp--;// 找到下一个出现的字符串
                if(temp < 0) break;
                else{
                    cha[temp]--;
                    ans += ('a' + temp);// 只填一个
                }
            }
        }
        return ans;
    }
};
// @lc code=end

