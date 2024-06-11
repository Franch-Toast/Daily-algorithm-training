/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include "string"

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0,right = s.size()-1;

        while(left < right)
        {
            while (left < s.size() && !isalnum(s[left])) // 获取左边的第一个字母
                left++;
            while (right >= 0 && !isalnum(s[right])) // 获取右边的第一个字母
                right--;

            if (left > right) // 做边界判断
                return 1;
            // 大小写转换
            char temp_left = (s[left] >= 'A' && s[left] <= 'Z') ? s[left] + 32 : s[left]; 
            char temp_right = (s[right] >= 'A' && s[right] <= 'Z') ? s[right] + 32 : s[right];

            if (temp_left != temp_right)
                return 0;
            left++;
            right--;
        }
        return 1;

    }
};
// @lc code=end

