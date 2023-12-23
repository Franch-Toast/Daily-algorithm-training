/*
 * @lc app=leetcode.cn id=1961 lang=cpp
 *
 * [1961] 检查字符串是否为数组前缀
 */

// @lc code=start
#include "vector"
#include "string"

using namespace std;

class Solution {
public:

    bool isPrefixString(string s, vector<string>& words) {
        int pos = 0;
        int index = 0;

        while(pos < s.size() && index < words.size())
        {
            int i = 0;
            while(i < words[index].size() && s[pos] == words[index][i])
            {
                pos++;
                i++;
            }
            if(i != words[index].size()) return 0;
            index++;
        }
        return pos==s.size();

    }
};
// @lc code=end

