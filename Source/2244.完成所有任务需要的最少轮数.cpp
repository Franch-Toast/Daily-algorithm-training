/*
 * @lc app=leetcode.cn id=2244 lang=cpp
 *
 * [2244] 完成所有任务需要的最少轮数
 */

// @lc code=start
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> diff;

        for(int task:tasks)
        {
            diff[task]++;
        }
        int ans = 0;
        for(auto [task,task_num] : diff)
        {
            if(task_num == 1) return -1;
            ans += task_num / 3 + (task_num % 3 == 0? 0:1);
        }
        return ans;


    }
};
// @lc code=end

