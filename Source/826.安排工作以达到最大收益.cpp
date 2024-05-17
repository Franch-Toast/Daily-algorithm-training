/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */

// @lc code=start
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;

        int m = difficulty.size(),n = worker.size();
        for(int i = 0; i < m; i++)
        {
            jobs.push_back({difficulty[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());

        int i = 0,best = 0,res = 0;
        for(int w:worker)
        {
            // 比较机智的做法
            while(i < n && w >= jobs[i].first)
            {
                // 用一个best来维护每次小于w的任务
                best = max(best,jobs[i].second);
                i++;
            }
            // best是满足小于w的最大的值，这个时候再加上
            res += best;
        }

        return res;

    }
};
// @lc code=end

