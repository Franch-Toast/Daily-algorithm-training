/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int i = 0, j = col - 1;
        while (i <= row - 1 && j >= 0)
        {
            if(matrix[i][j] == target) return 1;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return 0;

    }
};
// @lc code=end
