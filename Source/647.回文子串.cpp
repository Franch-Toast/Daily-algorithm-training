/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include "string"
#include "vector"

using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        // int num = 0;
        // int n = s.size();
        // for (int i = 0; i < n; i++) // 遍历回文中心点
        // {
        //     for (int j = 0; j <= 1; j++) // j = 0,中心是一个点，j=1,中心是两个点
        //     {
        //         int l = i;
        //         int r = i + j;
        //         while (l >= 0 && r < n && s[l--] == s[r++])
        //             num++;
        //     }
        // }
        // return num;

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        { // 注意遍历顺序
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    { // 情况一 和 情况二
                        result++;
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1])
                    { // 情况三
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
};

// @lc code=end
