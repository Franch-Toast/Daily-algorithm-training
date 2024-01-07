/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0,right = 0;

        int n = s.size();
        vector<int> num(26);
        int max_num = 0;

        for(; right < n; right++)
        {
            num[s[right] - 'A']++;
            max_num = max(max_num, num[s[right] - 'A']);
            // 维护出现在当前段内出现最多的字母的次数

            if(right + 1 - left - max_num > k) 
            // 如果在[left,right]段内其他的字母的数量超过了k，则左端点的长度极限到了
            // 如果没有超过k，则还有长度增长的机会，不需要移动左端点
            {
                num[s[left] - 'A']--; // 将左端点的字母去除出子字符串
                left++;// 左端点向右滑动
            }
        }
        // [left,right] 实际上就维护了过程中满足数量k个不同的最长的子字符串
        return right - left;// 注意right最后会到n，而不是n-1

    }
};
// @lc code=end

