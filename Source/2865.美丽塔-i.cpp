/*
 * @lc app=leetcode.cn id=2865 lang=cpp
 *
 * [2865] 美丽塔 I
 */

// @lc code=start
#include "vector"
#include "stack"

using namespace std;
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long res = 0;
        vector<long long> prefix(n), suffix(n);// 定义不同峰顶时候上坡、下坡的高度和
        stack<int> stack1, stack2;// 创建两个单调栈
     
        // 对不同峰顶进行遍历，同时对上坡的高度和进行记录，从前向后遍历
        for (int i = 0; i < n; i++) {
            // 跳过比峰顶的值大的点，这些点最多只能取峰顶的值
            while (!stack1.empty() && maxHeights[i] < maxHeights[stack1.top()]) {
                stack1.pop();
            }
            // 空栈时，说明前面的点都只能去峰顶的值
            if (stack1.empty()) {
                prefix[i] = (long long)(i + 1) * maxHeights[i];
            } 
            // 如果不是空栈，说明在该点与峰顶之间的点只能取峰顶的值，该点之前的点取前面遍历得到的结果
            else {
                prefix[i] = prefix[stack1.top()] + (long long)(i - stack1.top()) * maxHeights[i];
            }
            // 每个节点入栈
            stack1.emplace(i);
        }
        // 后文同理
        for (int i = n - 1; i >= 0; i--) {
            while (!stack2.empty() && maxHeights[i] < maxHeights[stack2.top()]) {
                stack2.pop();
            }
            if (stack2.empty()) {
                suffix[i] = (long long)(n - i) * maxHeights[i];
            } else {
                suffix[i] = suffix[stack2.top()] + (long long)(stack2.top() - i) * maxHeights[i];
            }
            stack2.emplace(i);
            res = max(res, prefix[i] + suffix[i] - maxHeights[i]);// 多计算了一次峰顶
        }
        return res;
    }
};
// @lc code=end

