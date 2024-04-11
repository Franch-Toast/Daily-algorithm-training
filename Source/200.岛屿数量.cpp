/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution
{
public:
    /* 遍历所有的陆地，在遍历的过程中对已遍历过的陆地进行标记，防止多次遍历 */
    void dfs(vector<vector<char>> &grid, int i, int j) // 由于不需要计算陆地的大小，所以直接在引用中更改标记即可，不需要返回值
    {
        if (!judgement(grid, i, j)) // 如果越界了直接返回
            return;
        if (grid[i][j] == '1') 
        {
            grid[i][j] = 2; // 更改标记
            /* 向四个方向延申 */
            dfs(grid, i - 1, j);
            dfs(grid, i + 1, j);
            dfs(grid, i, j - 1);
            dfs(grid, i, j + 1);
        }
    }
    bool judgement(vector<vector<char>> &grid, int i, int j) // 判断是否越界
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i >= n || j >= m)
            return false;
        else if (i < 0 || j < 0)
            return false;
        else
            return true;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == '1') // 如果发现了还没有被遍历的陆地
                {
                    ans++;           // 陆地数量+1
                    dfs(grid, i, j); // 进入递归
                }
            }
        }
        return ans;
    }
};
// @lc code=end
