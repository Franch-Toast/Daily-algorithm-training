/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
        {
            return s; // 一个字符本身就是回文串
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++)
        {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++)
            {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n)
                {
                    break;
                }

                if (s[i] != s[j]) // 左右边界不等，一定不是回文串
                {
                    dp[i][j] = false;
                }
                else
                {
                    if (j - i < 3) // 如果左右边界中间的数少于两个，则一定是回文串（j - i = L - 1）
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1]; // 如果多于两个，那么该字串是否是回文串取决于内缩的子串
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

// @lc code=end
