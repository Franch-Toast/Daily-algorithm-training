// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem73.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++)
        {
            if (!matrix[i][0])
            {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (!matrix[0][j])
            {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][j])
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][0] || !matrix[0][j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
        return;

        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++) // m行n列
        {
            for (int j = 0; j < n; j++)
            {
                if (!matrix[i][j])
                {
                    row[i] = col[j] = true; // 标记是否改为0
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] || col[j]) // 如果一旦满足该行或该列有标记
                {
                    matrix[i][j] = 0; // 这个元素置零
                }
            }
        }
    }
};
// @lc code=end
