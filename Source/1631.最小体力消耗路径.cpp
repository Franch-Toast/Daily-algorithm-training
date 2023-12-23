/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;


class Solution {
public:

    vector<vector<int>> direct={{-1,0},{0,1},{0,-1},{1,0}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        // 求解最大的最小值，使用二分的方法
        int left = 0, right= 1e6 -1;
        int row = heights.size(),col = heights[0].size();
        int ans;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            vector<int> seen(row * col);// 记录遍历过的节点
            queue<pair<int,int>> next;// 记录即将遍历的节点
            next.push({0,0});
            seen[0] = 1;
            while(!next.empty())// 只要还有节点没有遍历就要遍历
            {
                int cur_row = next.front().first;
                int cur_col = next.front().second;
                next.pop();
                for(int i = 0;i < 4; i++)
                {
                    int next_row = cur_row + direct[i][0];
                    int next_col = cur_col + direct[i][1];
                    if(next_col >= 0 && next_col < col && next_row >= 0 &&\
                    next_row < row && seen[next_row*col + next_col] ==0 && \
                    abs(heights[next_row][next_col]-heights[cur_row][cur_col]) <= mid)
                    {
                        next.push({next_row,next_col});
                        seen[next_row*col + next_col] = 1;
                    }
                }
            }
            if(seen[row*col-1] == 1) 
            {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;


    }
};
// @lc code=end

