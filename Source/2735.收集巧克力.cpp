/*
 * @lc app=leetcode.cn id=2735 lang=cpp
 *
 * [2735] 收集巧克力
 */

// @lc code=start
#include "vector"
#include "numeric"
#include "algorithm"

using namespace std;
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> f(nums); // 用来存储第k次操作后的成本
        long long ans = accumulate(f.begin(),f.end(),0LL);
        // 注意这里在累加的时候，一定要使用0LL，否则会溢出
        for(int k = 1; k < n; k++)// k-1次操作，每k次操作会是一次循环，第零次循环已经做过了
        {
            for(int i = 0; i < n; i++)
            {
                f[i] = min(f[i],nums[(i+k) % n]);
                // 每一次操作都对所有的类型的巧克力都做一次最小值，判断一下这次操作是否是最小的结果，保存在f[i]中
            }
            ans = min(ans, static_cast<long long>(k) * x + accumulate(f.begin(), f.end(), 0LL));
            // 强制类型转换，每次操作完后，进行一次当前操作结果下的计算，并获取一次最小值
        }
        return ans;
    }
};
// 实际的思想就是暴力，枚举操作次数，获取该操作次数下的最小成本

// @lc code=end

