/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start

#include "string"
#include "vector"

using namespace std;
class Solution
{
public:
    int dir_x[4] = {0, 0, -1, 1};
    int dir_y[4] = {-1, 1, 0, 0};
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(board, word, 0, i, j))
                    return 1;
            }
        }
        return 0;
    }

    bool dfs(vector<vector<char>> &board, string word, int index, int x, int y)
    {

        if (index == word.size())
            return 1;

        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[index])
            return 0;

        char temp = board[x][y];
        board[x][y] = '/'; // 标记，防止重复访问
        int res = 0;
        for (int i = 0; i < 4; i++)
        {
            if (res |= dfs(board, word, index + 1, x + dir_x[i], y + dir_y[i]))
            {
                return 1;
            }
        }
        board[x][y] = temp; // 恢复现场
        return 0;
    }
};
// @lc code=end
