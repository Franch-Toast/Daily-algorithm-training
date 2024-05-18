/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int ans = 0;
    bool dfs(vector<vector<int>> &grid, int x, int y, int &temp)
    {
        bool escape = 0; // bool变量，表示这一片陆地是否能够逃脱
        grid[x][y] = 0;
        temp++;
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()){
                escape = 1; // 表示能逃脱
                continue;
            }
            if (grid[nextx][nexty] == 0)
                continue;
            escape |= dfs(grid, nextx, nexty, temp); // 向后传递
        }
        return escape;// 返回这块陆地的逃脱结果
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) // 每次进入dfs都会将其置0表示已经搜索过了
                {
                    int temp = 0;
                    bool escape = dfs(grid, i, j, temp);
                    ans += temp * (1-escape); // 计算不能逃脱的数量
                }
            }
        }
        return ans;
    }
};
// @lc code=end

