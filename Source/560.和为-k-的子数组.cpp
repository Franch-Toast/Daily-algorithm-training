/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include "vector"
#include "unordered_map"

using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> cnt;
        int temp = 0;
        cnt[0]++;// 不要忘记了0元素的前缀和为0
        for (int num : nums)
        {
            temp += num; // 前缀和
            if (cnt.count(temp - k))
                ans += cnt[temp - k];
            cnt[temp]++;
        }
        return ans;
    }
};
// @lc code=end
