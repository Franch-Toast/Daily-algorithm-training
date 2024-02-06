/*
 * @lc app=leetcode.cn id=3001 lang=cpp
 *
 * [3001] 捕获黑皇后需要的最少移动次数
 */

// @lc code=start
#include "string"

using namespace std;
class Solution {
    bool ok(int l, int m, int r) {
        return m < min(l, r) || m > max(l, r);// m 在 l 的左边，或在 r 的右边
    }

public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e && (c != e || ok(b, d, f)) || // 车可以横向直接攻击到皇后，且象没有阻挡在中间
            b == f && (d != f || ok(a, c, e)) || // 车可以纵向直接攻击到皇后，且象没有阻挡在中间
            c - e == f - d && (a + b != e + f || ok(c, a, e)) || // 象以次对角线直接攻击到皇后，且车没有阻挡在中间（次对角线）
            c - e == d - f && (a - b != e - f || ok(c, a, e))) { // 象以主对角线直接攻击到皇后，且车没有阻挡在中间（主对角线）
            return 1;
        }
        return 2;// 最多只需要两次就一定可以捕获到
    }
};
// @lc code=end

/*
    查看灵神的题解
    https://leetcode.cn/problems/minimum-moves-to-capture-the-queen/solutions/2594432/fen-lei-tao-lun-jian-ji-xie-fa-pythonjav-aoa8/

    其中如何判断是否挡在两者中间？
    只要另一个棋子的位置不满足特征值或满足特征值但另一个方向上不会遮挡。
*/

