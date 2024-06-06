/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
#include "string"
#include "stack"
#include "unordered_map"
#include "unordered_set"
// #include "queue"

using namespace std;
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {

        // stack<char> st;
        unordered_map<char, int> cnt;
        unordered_set<char> show;
        string ans = "";
        for (char ch : s) // 统计每个字母的出现次数
            cnt[ch]++;

        for (char ch : s)
        {
            cnt[ch]--;
            if (show.count(ch)) // ans 中不能有重复字母
                continue;
            while (!ans.empty() && ch < ans.back() && cnt[ans.back()])
            {
                // (设 x=ans.back()) 如果 c < x，且右边还有 x，那么可以把 x 去掉，
                show.erase(ans.back()); // 标记 x 不在 ans 中
                ans.pop_back();
            }
            ans += ch;
            show.insert(ch); // 标记 c 在 ans 中
        }

        return ans;
    }
};
// @lc code=end
