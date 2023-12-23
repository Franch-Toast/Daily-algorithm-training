/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
#include "vector"
#include "numeric"
#include "algorithm"
#include <functional>
using namespace std;

class Solution {
public:

    bool dfs(int index, vector<int> &matchsticks, vector<int> &edges, int len) {
        if (index == matchsticks.size()) { // 如果所有的火柴都枚举完了，直接返回成功
            return true;
        }
        for (int i = 0; i < edges.size(); i++) {// 对每一条边进行填充
            edges[i] += matchsticks[index]; // 先直接将index号火柴分配给某一条边
            if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
            // 如果该边没有超过限制，同时在该火柴如此分配的同时下面的所有火柴都能够分配成功，则说明这根火柴的分配是正确的
                return true;
            }
            edges[i] -= matchsticks[index];
            // 没有从上一条if分支走，说明这根火柴分配给这一条边是错误的，将这根火柴去除掉，尝试将这根火柴分配给其他的边
        }
        //如果在上面没有返回true，说明这根index的火柴无法分配成功
        return false;
    }

    bool makesquare(vector<int> &matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0) {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 从小到大排序以减少搜索量

        vector<int> edges(4);
        return dfs(0, matchsticks, edges, totalLen / 4);
    }
};
// @lc code=end

