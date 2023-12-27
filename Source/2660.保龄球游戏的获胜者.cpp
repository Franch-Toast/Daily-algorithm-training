/*
 * @lc app=leetcode.cn id=2660 lang=cpp
 *
 * [2660] 保龄球游戏的获胜者
 */

// @lc code=start
#include "vector"

using namespace std;

class Solution {
public:

    int getscore(vector<int>& player)
    {
        int flag = player[0] == 10?1:0;
        int score = player[0];
        int n = player.size();

        for(int i = 1;i < n;i++)
        {
            if(flag == 1) score += player[i] * 2;
            else score += player[i];
            if(player[i] == 10) flag = 1;
            else if(player[i-1] != 10) flag = 0;
        }
        return score;
    }

    int isWinner(vector<int>& player1, vector<int>& player2) {

        int score1 = getscore(player1);
        int score2 = getscore(player2);

        return score1 > score2 ? 1 : (score1 == score2 ? 0 : 2);
    }
};
// @lc code=end

