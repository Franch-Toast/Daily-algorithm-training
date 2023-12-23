/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 *
 * [1901] 寻找峰值 II
 */

// @lc code=start
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left = 0,right = mat.size() - 2;
        int n = mat[0].size();

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            // 获取最大值的索引
            int temp_index = max_element(mat[mid].begin(),mat[mid].begin() + n) - mat[mid].begin();

            if(mat[mid][temp_index] < mat[mid+1][temp_index]) left = mid + 1; // 如果当前行的最大值位置的下一行的值比这个值小，那么说明下面必有峰值
            else right = mid - 1;// 否则峰值一定在上面的行中
        }

        return {left,(int)(max_element(mat[left].begin(),mat[left].begin() + n) - mat[left].begin())};
    }
};

// 此题的二分比较难发现，可以参看灵神的题解(https://leetcode.cn/problems/find-a-peak-element-ii/solutions/2571587/tu-jie-li-yong-xing-zui-da-zhi-pan-duan-r4e0n/)

// @lc code=end

