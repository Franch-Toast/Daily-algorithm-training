/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int left = 0, right = matrix.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] < target)
                left = mid + 1;
            else if (matrix[mid][0] > target)
                right = mid - 1;
            else
                return 1;
        }
        int row = right;
        if (right < 0) // 防止整个矩阵中的第一个就已经大于target了
            return 0;

        left = 0;
        right = matrix[0].size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] < target)
                left = mid + 1;
            else if (matrix[row][mid] > target)
                right = mid - 1;
            else
                return 1;
        }
        return 0;
    }
};
// @lc code=end
