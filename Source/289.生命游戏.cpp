// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem289.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
#include "vector"
using namespace std;
class Solution
{
public:
    int dir[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, -1, 1, 1, 1, -1, -1, 1, -1};
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> copy = board;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num = 0;
                for (int k = 0; k < 8; k++)
                {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    num += copy[x][y];
                }
                if (num < 2 || num > 3)
                    board[i][j] = 0;
                else if (num == 3)
                    board[i][j] = 1;
            }
        }
    }
};
// @lc code=end

