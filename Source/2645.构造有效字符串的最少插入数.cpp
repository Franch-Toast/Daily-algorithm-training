/*
 * @lc app=leetcode.cn id=2645 lang=cpp
 *
 * [2645] 构造有效字符串的最少插入数
 */

// @lc code=start
#include "string"

using namespace std;
class Solution {
public:
    int addMinimum(string s) {
        int ans = s[0] + 2 - s.back();
        for (int i = 1; i < s.length(); i++) {
            ans += (s[i] + 2 - s[i - 1]) % 3;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int addMinimum(string s) {
//         int t = 1;
//         for (int i = 1; i < s.length(); i++) {
//             t += s[i - 1] >= s[i]; // 必须生成一个新的 abc
//         }
//         return t * 3 - s.length();
//     }
// };


// 查看灵神的题解：https://leetcode.cn/problems/minimum-additions-to-make-valid-string/solutions/2229526/kao-lu-xiang-lin-zi-mu-pythonjavacgo-by-m9yrc/


// @lc code=end

