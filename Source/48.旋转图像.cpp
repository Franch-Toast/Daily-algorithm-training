/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include "vector"

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int row = matrix.size();

        int temp;
        for (int i = 0; i < (row) / 2; i++)
        {
            for (int j = 0; j < (row + 1) / 2; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[row - 1 - j][i];
                matrix[row - 1 - j][i] = matrix[row - 1 - i][row - 1 - j];
                matrix[row - 1 - i][row - 1 - j] = matrix[j][row - 1 - i];
                matrix[j][row - 1 - i] = temp;
            }
        }
    }
};
// @lc code=end
