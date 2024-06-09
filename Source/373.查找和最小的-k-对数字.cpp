/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        priority_queue<tuple<int, int, int>> pq;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < min(n, k); i++)         // 至多 k 个
            pq.emplace(-nums1[i] - nums2[0], i, 0); // 取相反数变成小顶堆
        while (!pq.empty() && ans.size() < k)
        {
            auto [_, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < m)
                pq.emplace(-nums1[i] - nums2[j + 1], i, j + 1);
        }
        return ans;
    }
};

// @lc code=end
