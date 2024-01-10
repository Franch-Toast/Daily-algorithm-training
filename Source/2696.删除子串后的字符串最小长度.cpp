/*
 * @lc app=leetcode.cn id=2696 lang=cpp
 *
 * [2696] 删除子串后的字符串最小长度
 */

// @lc code=start
#include "string"
#include "stack"
#include "iostream"

using namespace std;
class Solution {
public:
    int minLength(string s) {
        stack<char> st;// 使用栈
        int index = 0;
        while(index < s.size())
        {
            if (st.size() == 0 || (st.top() != 'A' && st.top() != 'C'))
            {
                st.push(s[index++]);
                continue;
            }
            if ((st.top() == 'A' && s[index] == 'B') || (st.top() == 'C' && s[index] == 'D'))
            {
                st.pop();
                index++;
            }
            else{
                st.push(s[index++]);
            }
        }
        return st.size();
    }
};
// @lc code=end

/*下面的做法 使用递归，但是会出现问题，不了解为什么会越界*/
// class Solution
// {
// public:
//     int minLength(string s)
//     {
//         for (int index = 0; index < s.length() - 1; index++)
//         {
//             cout << s.length() << endl;
//             if (s[index] == 'A' && s[index + 1] == 'B')
//             {
//                 string new_string = s.substr(0, index) + s.substr(index + 2, s.length() - (index + 2));
//                 s.clear();
//                 return minLength(new_string);
//             }
//             if (s[index] == 'C' && s[index + 1] == 'D')
//             {
//                 string new_string = s.substr(0, index) + s.substr(index + 2, s.length() - (index + 2));
//                 s.clear();
//                 return minLength(new_string);
//             }
//         }
//         return s.size();
//     }
// };