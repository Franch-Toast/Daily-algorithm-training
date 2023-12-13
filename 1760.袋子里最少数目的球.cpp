/*
 * @lc app=leetcode.cn id=1760 lang=cpp
 *
 * [1760] 袋子里最少数目的球
 */

// @lc code=start
#include "queue"
#include "vector"
#include "algorithm"
#include <numeric>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // 还是经典的求最小的最大值题目
        int left = 1, right = *max_element(nums.begin(), nums.end());//获取当前袋子中最多的球，作为二分法的右边界。
        int ans = 0;
        while (left <= right) {
            int y = (left + right) / 2;
            long long ops = 0;
            for (int x: nums) {
                ops += (x - 1) / y;
                // 对于x个小球，能将按y个将其剥离需要的次数
            }
            if (ops <= maxOperations) {
                ans = y;
                right = y - 1;
            }
            else {
                left = y + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

