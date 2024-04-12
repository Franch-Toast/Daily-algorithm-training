/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
#include "vector"
#include "queue"
#include "iostream"
using namespace std;
class Solution
{
public:
    int badtime[10][10];          // 记录每个橘子的腐败时间
    int cnt = 0;                  // 记录新鲜橘子数
    int dir_x[4] = {0, 0, 1, -1}; // 方向向量上下组合形成向右、向左，向下，向上
    int dir_y[4] = {1, -1, 0, 0};

    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q; // 创建一个队列，队列中的元素为腐烂的橘子的坐标
        memset(badtime,-1,sizeof(badtime)); // 将所有的橘子的腐烂时间都设定为未腐烂
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});// 坐标入队
                    badtime[i][j] = 0; // 该坐标的橘子标记为第0分钟就腐烂了
                }
                else if (grid[i][j] == 1) cnt++; // 记录新鲜橘子的个数
            }
        }
        // 开始BFS
        int ans = 0; // 用来记录最短全部腐烂时间
        int dx,dy;
        while(!q.empty())
        {
            auto[row,col] = q.front();
            q.pop();
            for(int i = 0;i<4;i++)
            {
                dx = row + dir_x[i];
                dy = col + dir_y[i];

                // 如果越界或不越界但已经腐烂或没有橘子则continue
                if (dx < 0 || dy < 0 || dx >= m || dy >= n || grid[dx][dy] == 2 || grid[dx][dy] == 0)
                    continue;

                // 当前坐标下的一定是相邻的新鲜橘子
                badtime[dx][dy] = badtime[row][col] + 1;// 该橘子的腐败时间是源橘子传染来的
                q.push({dx,dy});


                grid[dx][dy] = 2;
                ans = badtime[dx][dy];
                if(--cnt == 0) break;
            }
            
        }

        return cnt == 0 ? ans : -1;
    }
};
// @lc code=end
