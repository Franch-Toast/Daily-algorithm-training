/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include "vector"
#include "queue"

using namespace std;
class Solution
{
private:
    queue<pair<int, int>> q;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y)
    {
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
                continue; // 越界了，直接跳过
            if (!visited[nextx][nexty] && grid[nextx][nexty] == '1')
            { // 没有访问过的 同时 是陆地的

                visited[nextx][nexty] = true;
                dfs(grid, visited, nextx, nexty);
            }
        }
    }

    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        while (!q.empty())
        {
            // int n = q.size();
            int nextx = q.front().first;
            int nexty = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++)
            {
                int x = nextx + dir[i][0];
                int y = nexty + dir[i][1];

                if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || grid[x][y] == '0')
                {
                    continue;
                }
                    
                q.push({x, y});
                visited[x][y] = 1;
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    visited[i][j] = true;
                    result++;           // 遇到没访问过的陆地，+1
                    q.push({i, j});     // BFS时使用，入队列
                    bfs(grid, visited); // BFS
                    // dfs(grid, visited, i, j); // 将与其链接的陆地都标记上 true
                }
            }
        }
        return result;
    }
};
// @lc code=end
