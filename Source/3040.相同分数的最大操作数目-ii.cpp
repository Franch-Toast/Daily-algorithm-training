/*
 * @lc app=leetcode.cn id=3040 lang=cpp
 *
 * [3040] 相同分数的最大操作数目 II
 */

// @lc code=start
#include "vector"
#include "functional"

using namespace std;

/* 区间DP */
class Solution
{
public:
    int maxOperations(vector<int> &nums)
    {
        int n = nums.size();
        int memo[n][n];
        
        // 对不同的目标target进行判断，总共三种情况
        auto helper = [&](int i, int j, int target) -> int 
        { 
            memset(memo, -1, sizeof(memo));
            function<int(int, int)> dfs = [&](int i, int j) -> int
            {
                if (i >= j) // 数组中少于一个元素
                {
                    return 0;
                }
                if (memo[i][j] != -1) // 此前已经计算过了，记忆化返回
                {
                    return memo[i][j];
                }
                int ans = 0;
                if (nums[i] + nums[i + 1] == target) // 前两个删除
                {
                    ans = max(ans, 1 + dfs(i + 2, j));
                }
                if (nums[j - 1] + nums[j] == target) // 后两个删除
                {
                    ans = max(ans, 1 + dfs(i, j - 2));
                }
                if (nums[i] + nums[j] == target)// 前后两个删除
                {
                    ans = max(ans, 1 + dfs(i + 1, j - 1));
                }
                memo[i][j] = ans; // 记忆化
                return ans;
            };
            return dfs(i, j); // 进行dp搜索
        };

        int res = 0;
        // 三种target计算
        res = max(res, helper(0, n - 1, nums[0] + nums[n - 1]));
        res = max(res, helper(0, n - 1, nums[0] + nums[1]));
        res = max(res, helper(0, n - 1, nums[n - 2] + nums[n - 1]));
        return res;
    }
};

// /* 使用深搜 会超时 其实这里在tryoperation函数中（或全局，但是每次aim变化 需要清空数组）开辟一个数组来记忆化保存就可以解决了 */
// class Solution
// {
// public:
//     int tryoperation(vector<int> nums, int begin, int end, int aim, int cur)
//     {
//         if (end - begin + 1 < 2)
//             return cur;
//         int temp = cur;
//         if (nums[begin] + nums[begin + 1] == aim)
//             temp = max(temp, tryoperation(nums, begin + 2, end, aim, cur + 1));
//         if (nums[begin] + nums[end] == aim)
//             temp = max(temp, tryoperation(nums, begin + 1, end - 1, aim, cur + 1));
//         if (nums[end - 1] + nums[end] == aim)
//             temp = max(temp, tryoperation(nums, begin, end - 2, aim, cur + 1));
//         return temp;
//     }

//     int maxOperations(vector<int> &nums)
//     {
//         int ans = 0;
//         ans = max(ans, tryoperation(nums, 0, nums.size() - 1, nums[0] + nums[nums.size() - 1], 0));
//         ans = max(ans, tryoperation(nums, 0, nums.size() - 1, nums[0] + nums[1], 0));
//         ans = max(ans, tryoperation(nums, 0, nums.size() - 1, nums[nums.size() - 1] + nums[nums.size() - 2], 0));
//         return ans;
//     }
// };
// @lc code=end
