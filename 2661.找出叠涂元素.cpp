/*
 * @lc app=leetcode.cn id=2661 lang=cpp
 *
 * [2661] 找出叠涂元素
 */

// @lc code=start
#include "vector"
#include "unordered_map"
#include "algorithm"


using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // 获取矩阵的行列数
        int n = mat[0].size();
        int m = mat.size(); 
        vector<int> cnt_row(m);
        vector<int> cnt_col(n);
        unordered_map<int,tuple<int,int>> pos;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0;j < n; j++)
            {
                pos[mat[i][j]] = {i,j};
            }
        }
        
        // int ret = INT_MAX;
        for(int i = 0; i < m*n; i++)
        {
            int temp_row = get<0>(pos[arr[i]]);
            int temp_col = get<1>(pos[arr[i]]);
            ++cnt_row[temp_row];
            ++cnt_col[temp_col];
            if(cnt_row[temp_row] == n || cnt_col[temp_col] == m)
            {
                return i;
            }
        }

        return -1;
    }
};



// @lc code=end

