/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int dir[4][2] = {0,1,0,-1,1,0,-1,0};
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited,int x,int y)
    {
        visited[x][y] = true;

        for(int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];

            if(nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size()|| visited[nextx][nexty]) continue;
            if(board[nextx][nexty] == 'X')
                dfs(board,visited,nextx,nexty);
        }
        return ;
    }

    int countBattleships(vector<vector<char>> &board)
    {
        int ans = 0;
        int m = board.size(),n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m ; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(board[i][j] == 'X' && visited[i][j] == false)
                {
                    ans++;
                    dfs(board,visited,i,j);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

