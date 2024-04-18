/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include "string"
#include "stack"
#include "ctype.h"
using namespace std;
class Solution
{
public:
    string decodeString(string s)
    {
        stack<pair<string, int>> st;
        string res = "";
        int mul = 0;
        for (auto c : s)
        {
            if (c == '[')
            {
                st.emplace(res, mul);
                res = "";
                mul = 0;
            }
            else if (c == ']')
            {
                auto [last_res, cur_mul] = st.top();
                st.pop();
                string tmp = last_res;
                for (int i = 0; i < cur_mul; i++)
                    tmp += res;
                res = tmp;
            }
            else if ('0' <= c && c <= '9')
            {
                mul = mul * 10 + (c - '0');
            }
            else
            {
                res += c;
            }
        }
        return res;
    }
};
// @lc code=end

