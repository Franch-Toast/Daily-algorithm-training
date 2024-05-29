/*
 * @lc app=leetcode.cn id=2981 lang=cpp
 *
 * [2981] 找出出现至少三次的最长特殊子字符串 I
 */

// @lc code=start
#include "string"
using namespace std;
const int N = 60;

class Solution
{
public:
    int maximumLength(string s)
    {
        int cnt[26][N] = {0}; // 26个字母连续出现j次的数量

        int l = 0, r = 0, n = s.size();
        int res = -1;
        while (r < n)
        {
            char cur_char = s[r];
            int cur = cur_char - 'a';
            while (r + 1 < n && s[r + 1] == cur_char)
                ++r;
            int cur_len = r - l + 1; // 获取最长的特殊字符串为多长
            for (int i = 1; i <= cur_len; i++) // 计算 i 长度的字串能在该特殊字符串中出现几次
            {
                cnt[cur][i] += (cur_len - i + 1); // 使用+=是为了防止后面这个子串再次出现，可以继续增加
                if (cnt[cur][i] > 2 && i > res) // 满足出现的次数大于3，维护最大值
                {
                    res = i;
                }
            }
            ++r; // 判断下一个特殊字符串
            l = r; // 更新左边界
        }

        return res;
    }
};
// @lc code=end

