/*
 * @lc app=leetcode.cn id=2697 lang=cpp
 *
 * [2697] 字典序最小回文串
 */

// @lc code=start
#include "vector"
#include "string"

using namespace std;


class Solution {
public:
    string makeSmallestPalindrome(string s) {
        // int right = s.size() - 1,left = 0;
        // while(left < right)
        // {
            
        //     if(s[left] < s[right]) s[right] = s[left]; 
        //     else if(s[left] > s[right]) s[left] = s[right];
        //     left++;
        //     right--;
        // }
        // return s;

        for(int right = s.size() - 1,left = 0;left < right;left++,right--)
        {
            if(s[left] < s[right]) s[right] = s[left]; 
            else if(s[left] > s[right]) s[left] = s[right];
        }

        return s;

    }
};
// @lc code=end

