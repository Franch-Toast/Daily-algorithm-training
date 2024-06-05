/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
#include "string"
#include "deque"
#include "vector"

using namespace std;
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        vector<char> stk;
        for (auto &digit : num)
        {
            while (stk.size() > 0 && stk.back() > digit && k) // 必须是单调非递减的形式
            {
                stk.pop_back();
                k -= 1;
            }
            stk.push_back(digit);
        }

        for (; k > 0; --k) // 如果没有去除干净，直接把后面的数字去除干净
        {
            stk.pop_back();
        }

        string ans = "";
        bool isLeadingZero = true; // 表明是否出现前导0
        for (auto &digit : stk)
        {
            if (isLeadingZero && digit == '0')
            {
                continue;
            }
            isLeadingZero = false;// 后续出现的0不需要考虑前导0的情况了
            ans += digit;
        }
        return ans == "" ? "0" : ans;
    }
};

// @lc code=end
