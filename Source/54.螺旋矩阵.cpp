/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        /* 用四个变量来记录起始和结束位置，以一个圈为一个循环，每一次遍历一条边后需要将边界更新 */

        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        int start_row = 0, start_col = 0;
        vector<int> ans;
        int row = 0, col = 0;
        while (1)
        {
            for (col = start_col; col <= n; col++)
                ans.push_back(matrix[start_row][col]);
            if (++start_row > m)
                break;

            for (row = start_row; row <= m; row++)
                ans.push_back(matrix[row][n]);
            if (start_col > --n)
                break;

            for (col = n; col >= start_col; col--)
                ans.push_back(matrix[m][col]);
            if (start_row > --m)
                break;

            for (row = m; row >= start_row; row--)
                ans.push_back(matrix[row][start_col]);
            if (++start_col > n)
                break;
        }
        return ans;
    }
};
// @lc code=end
