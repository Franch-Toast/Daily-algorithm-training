/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
#include "vector"
#include "unordered_set"
#include "numeric"
using namespace std;
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        unordered_set<int> index; // 用来存放老板生气时候的索引，相当于拿空间换时间了（遍历）
        int ans = 0;              // 用来存放老板不使用秘密技巧时顾客满意的数量
        int better = 0;           // 用来存放老板使用秘密技巧时，满意顾客的增加量的最大值
        for (int i = 0; i < n; i++)
        {
            if (!grumpy[i])
            {
                ans += customers[i];
                customers[i] = 0;
            }
            else
            {
                index.insert(i);
            }
        }
        for (int when : index)
        {
            if (when + minutes - 1 < n)
                better = max(better, accumulate(customers.begin() + when, customers.begin() + when + minutes, 0));
            else
                better = max(better, accumulate(customers.begin() + when, customers.end(), 0));
        }
        return ans + better;
    }
};
// @lc code=end
