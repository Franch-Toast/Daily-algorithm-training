/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int m = s.size(), n = p.size();
        if (m < n)
            return {};

        unordered_map<char, int> cnt;
        for (char ch : p)
            ++cnt[ch];
        vector<int> ans;
        for (int l = 0, r = 0; r < m; r++)
        {
            --cnt[s[r]];
            while (cnt[s[r]] < 0)
            {
                ++cnt[s[l]]; // 这里直接加就好了，不需要考虑在p中有没有，因为有字符个数来约束，一旦没有，一定会超字符总数的
                l++;
            }
            if (r - l + 1 == n)
                ans.push_back(l);
        }
        return ans;
    }
};
// @lc code=end
