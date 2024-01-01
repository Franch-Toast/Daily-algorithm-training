/*
 * @lc app=leetcode.cn id=1886 lang=cpp
 *
 * [1886] 判断矩阵经轮转后是否一致
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& mat,int n)
    {
        for (int i = 0; i < n / 2; ++i)
        // 如果是偶数行，则直接遍历上面一半
        // 如果是奇数行，则最中间的不会遍历到，恰好最中间的是不需要旋转的
        {
            for (int j = 0; j < (n + 1) / 2; ++j)
            // 对于列的遍历，需要考虑到奇数列也需要进行旋转了，否则会出现中间的十字是不旋转的
            {
                // 下面进行的是逆时针旋转，影响不大
                int temp = mat[i][j];
                mat[i][j] = mat[n - 1 - j][i];
                mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
                mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
                mat[j][n - 1 - i] = temp;
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();    
        for(int i = 0; i < 4; i++)
        {
            rotate(mat,n);
            if(mat == target) return 1;
        }
        return 0;
    }
};
// @lc code=end

