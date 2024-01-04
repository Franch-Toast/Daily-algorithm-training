/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> mask(m,0);// 用来记录matrix的行的二进制表示
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                mask[i] += matrix[i][j] << (n - 1 - j);
                // 把每一行表现为对应的二进制存入mask
            }
        }

        int res = 0;
        int cur = 0;// 选中列的二进制表示
        int limit = (1 << n);// 枚举的最大值，不可能超过该值，即所有列被选中
        while((++cur)<limit)
        {
            if(__builtin_popcount(cur) != numSelect) continue;// 选择的列数不等于题目给出的列数
            int t = 0; // 保存覆盖的行的数量
            for(int j = 0; j < m; j++)// 判断每一行是否被覆盖
            {
                if((mask[j] & cur) == mask[j]) t++;
                // 1 & 1 = 1，如果cur选中的列数恰好覆盖这一行的所有1 ，则得到的结果恰好就是这一行的mask
            }
            res = max(res,t); // 维护结果
        }
        return res;
    }
};
// @lc code=end

// 关于__builtin_popcount： https://blog.csdn.net/m0_65736560/article/details/131592266
