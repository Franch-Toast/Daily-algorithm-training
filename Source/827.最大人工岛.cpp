// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem827.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

// @lc code=start

#include "vector"
#include "unordered_map"
#include "unordered_set"

using namespace std;
class Solution
{
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int count = 0;
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y,int mark)
    {
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid.size())
                continue;
            if (visited[nextx][nexty] == false && grid[nextx][nexty] == 1)
            {
                visited[nextx][nexty] = true;
                grid[nextx][nexty] = mark;
                count++;
                dfs(grid,visited,nextx,nexty,mark);
            }
        }
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int ans = 1;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        unordered_map<int,int> island;
        bool isAllGrid = true; // 标记是否整个地图都是陆地
        int mark = 2; // 不能从1开始标记，不然会变成岛屿
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    isAllGrid = false;
                if (visited[i][j] == false && grid[i][j] == 1)
                {
                    count = 1;
                    grid[i][j] = mark;
                    visited[i][j] = true;
                    dfs(grid, visited, i, j,mark);
                    island[mark] = count;
                    mark++;
                }
            }
        }
        if (isAllGrid)
            return n * n; // 如果都是陆地，返回全面积

        for(int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int cur = 1;
                    unordered_set<int> vis; // 防止多次访问同一片岛屿
                    for (int k = 0; k < 4; k++)
                    {
                        int nextx = i + dir[k][0];
                        int nexty = j + dir[k][1];
                        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid.size())
                            continue;
                        if (grid[nextx][nexty] != 0 && !vis.count(grid[nextx][nexty]))
                        {
                            vis.insert(grid[nextx][nexty]);
                            cur += island[grid[nextx][nexty]];
                        }
                    }
                    ans = max(ans,cur);  
                }
            }
        }

        return ans;
    }
};
// @lc code=end
