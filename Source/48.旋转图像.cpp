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
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m / 2; i++)
        {
            for (int j = 0; j < (n + 1) / 2; j++)
            {
                int temp = matrix[i][j];

                matrix[i][j] = matrix[m - j - 1][i];
                matrix[m - j - 1][i] = matrix[m - i - 1][n - j - 1];
                matrix[m - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};
// @lc code=end
