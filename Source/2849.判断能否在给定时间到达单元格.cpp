/*
 * @lc app=leetcode.cn id=2849 lang=cpp
 *
 * [2849] 判断能否在给定时间到达单元格
 */

// @lc code=start
#include "algorithm"
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // 找到到达终点的最短时间 min_time
        // 对角线 -> 两条直角边，可以加 1s ，而左右来回一次（1->2->1）可以加2s，实现所有时间的可行

        if (sx == fx && sy == fy)
            return t != 1;
        return max(abs(sx - fx), abs(sy - fy)) <= t;

    }
};
// @lc code=end

