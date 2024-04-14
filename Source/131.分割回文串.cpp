/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include "string"
#include "vector"
#include "functional"

using namespace std;

class Solution
{
    bool isPalindrome(string &s, int left, int right) // 判断 [left,right] 是否回文
    {
        while (left < right)
            if (s[left++] != s[right--])
                return false;
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.length();
        function<void(int)> dfs = [&](int i)
        {
            if (i == n) // 递归到结尾了
            {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; ++j)
            {                              // 枚举子串的结束位置
                if (isPalindrome(s, i, j)) // 截取字串，并判断是否是回文子串
                {
                    path.push_back(s.substr(i, j - i + 1)); // 加入集合
                    dfs(j + 1);                             // 从这个位置向后继续找回文子串
                    path.pop_back();                        // 恢复现场
                }
            }
        };
        dfs(0);
        return ans;
    }
};

// @lc code=end
