/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution
{
public:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int ans = 0;
    void dfs(vector<vector<int>> &grid, int x, int y, int &temp)
    {
        grid[x][y] = 0;
        temp++;
        for(int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size() || grid[nextx][nexty] == 0) continue;
            dfs(grid,nextx,nexty,temp);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) // 每次进入dfs都会将其置0表示已经搜索过了
                {
                    int temp = 0;
                    dfs(grid, i, j, temp);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
