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
        
        int n = s.size();
        vector<int> dp(n+1);

        dp[0] = 1;
        
        for(int i = 0; i < n; i++)
        {
            // 当前位置已经失败了，所以不用计算后续了
            if(dp[i] == 0) continue; 
            for(string str: wordDict)
            {
                int length = str.size();
                if(i + length <= n && str == s.substr(i,length)) 
                {
                    dp[i+length] = 1;
                    // 注意下面的不能break，因为这是以起点为计算，而不是以终点为计算的，所以要获取到所有的结果
                    // break; // 该位置能成功，直接break
                }
            }
        }
        
        return dp[n];
        
        
        
        
        
        // auto wordDictSet = unordered_set<string>();
        // for (auto word : wordDict)
        // {
        //     wordDictSet.insert(word);
        // }
        // // dp[i] 表示字符串 s 前 i 个字符组成的字符串 s[0..i−1] 是否能被空格拆分成若干个字典中出现的单词。
        // auto dp = vector<bool>(s.size() + 1);
        // dp[0] = true;
        // for (int i = 1; i <= s.size(); ++i) // 对每一个位置进行遍历
        // {
        //     for (int j = 0; j < i; ++j) // 进行记忆化遍历
        //     {
        //         // 如果 以 j 为结尾的字符串是能够被组成的（在前面一定被遍历过并记忆），且在字典中可以找到[j..i]这部分的单词
        //         if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end())
        //         {
        //             dp[i] = true;
        //             break;// 不需要继续遍历了，表明到这里就可以被组成，不管是通过何种方式组成的
        //         }
        //     }
        // }

        // return dp[s.size()]; // 返回
    }
};
// @lc code=end
