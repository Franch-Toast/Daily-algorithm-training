/*
 * @lc app=leetcode.cn id=2828 lang=cpp
 *
 * [2828] 判别首字母缩略词
 */

// @lc code=start
#include "vector"
#include "string"

using namespace std;
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int right = 0;
        int n = s.size(),m = words.size();
        if(n != m) return false;
        for(string str:words)
        {
            if(str[0] != s[right++]) return false;
        }
        return true;


    }
};
// @lc code=end

