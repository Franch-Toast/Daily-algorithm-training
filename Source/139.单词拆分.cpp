// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem139.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include "string"
#include "vector"
#include "unordered_set"

using namespace std;
class Solution
{
public:
    /* 使用回溯算法，会超时 */

    // bool dfs(string s, vector<string> &wordDict)
    // {
    //     //int n = wordDict.size();
    //     if(s.size() <= 0) return 1;
    //     for(string str:wordDict)
    //     {
    //         int length = str.size();
    //         if (s.size() < length || s.substr(0, length) != str)
    //             continue;
    //         if (dfs(s.substr(length, s.size() - length),wordDict)) return 1;
    //     }
    //     return 0;
    // }

    // bool wordBreak(string s, vector<string> &wordDict)
    // {
    //     return dfs(s,wordDict);
    // }

    /* 使用动态规划 */

    bool wordBreak(string s, vector<string> &wordDict)
    {
        auto wordDictSet = unordered_set<string>();
        for (auto word : wordDict)
        {
            wordDictSet.insert(word);
        }
        // dp[i] 表示字符串 s 前 i 个字符组成的字符串 s[0..i−1] 是否能被空格拆分成若干个字典中出现的单词。
        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) // 对每一个位置进行遍历
        {
            for (int j = 0; j < i; ++j) // 进行记忆化遍历
            {
                // 如果 以 j 为结尾的字符串是能够被组成的（在前面一定被遍历过并记忆），且在字典中可以找到[j..i]这部分的单词
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end())
                {
                    dp[i] = true;
                    break;// 不需要继续遍历了，表明到这里就可以被组成，不管是通过何种方式组成的
                }
            }
        }

        return dp[s.size()]; // 返回
    }
};
// @lc code=end
