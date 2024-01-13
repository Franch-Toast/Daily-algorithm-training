/*
 * @Author: Franch-Toast
 * @Date: 2024-01-13 16:04:43
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-13 16:10:12
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
#include "string"

using namespace std;
class Solution {
public:
    bool flag = 0;// 是否已经删除了一个字符
    bool validPalindrome(string s) {
        int left = 0,right = s.size() - 1;    
        while(left < right)
        {
            if(s[left] != s[right])
            {
                if(flag == 1) return 0;
                flag = 1;// 表明删除了一个字符，标志位置1
                return validPalindrome(s.substr(left,right-left)) | validPalindrome(s.substr(left+1,right-left));
            }
            left++;
            right--;
        }
        return 1;
    }
};
// @lc code=end

