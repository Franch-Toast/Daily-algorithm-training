/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include "vector"
#include "unordered_set"

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cnt;
        int ans = 0;
        for (int num : nums) cnt.insert(num);

        for (int num : nums)
        {
            if (!cnt.count(num - 1))
            {
                int cur_cnt = 1;
                while(cnt.count(++num)) cur_cnt++;
                ans = max(ans,cur_cnt);
            }
        }
        return ans;
    }
};
// @lc code=end

