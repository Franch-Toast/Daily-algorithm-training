/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include "string"
#include "vector"

using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> num(26);
        for(char ch:magazine)
        {
            num[ch - 'a']++;
        }
        for(char ch:ransomNote)
        {
            if(num[ch - 'a']-- == 0) return 0;
        }
        return 1;
    }
};
// @lc code=end

