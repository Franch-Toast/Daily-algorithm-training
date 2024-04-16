/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include "string"
#include "stack"
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char ch : s)
        {
            if (ch == '(')
                st.push(')');
            else if (ch == '{')
                st.push('}');
            else if (ch == '[')
                st.push(']');
            else
            {
                if (st.empty())
                    return 0;
                char temp = st.top();
                if (ch == temp) st.pop();
                else return 0;
            }
        }
        return st.empty();
    }
};
// @lc code=end
