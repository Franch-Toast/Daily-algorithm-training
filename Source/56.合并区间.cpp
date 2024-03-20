// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem56.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        vector<int> cur = intervals[0];
        for(int i = 1;i < intervals.size(); i++)
        {
            if(cur[1] >= intervals[i][0])
            {
                cur[1] = max(cur[1],intervals[i][1]); // 取两者右边界的最大值
            }
            else
            {
                ans.push_back(cur);
                cur = intervals[i];
            }
        }
        ans.push_back(cur);// 最后的结果也要push进去
        return ans;
    }
};
// @lc code=end

