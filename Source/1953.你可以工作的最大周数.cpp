/*
 * @lc app=leetcode.cn id=1953 lang=cpp
 *
 * [1953] 你可以工作的最大周数
 */

// @lc code=start
#include "vector"
#include "algorithm"
#include "numeric"
using namespace std;
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long max_num = *max_element(milestones.begin(),milestones.end());
        long long rest_num = accumulate(milestones.begin(), milestones.end(),0LL) - max_num;

        return max_num > rest_num + 1 ? 2*rest_num + 1 : rest_num + max_num;
    }
};
// @lc code=end

