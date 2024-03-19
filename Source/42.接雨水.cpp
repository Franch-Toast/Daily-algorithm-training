/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include "vector"
#include "stack"
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) // 对每一根柱子进行遍历
        {
            /* 栈内还有其他的柱子，当前面不再是“向下的阶梯状”的柱子，而是“微笑曲线” */
            while (!st.empty() && height[i] >= height[st.top()])
            {
                // 获取前一个最小的柱子，实际上也就是底的高度，比这个底小的部分在之前的迭代中已经被填平了
                int bottom_h = height[st.top()];
                st.pop();
                if (st.empty()) // 如果栈为空了，说明无法积水了，直接跳出，
                {
                    break;
                }
                int left = st.top();                              // 第二小的柱子
                int dh = min(height[left], height[i]) - bottom_h; // 面积的高
                ans += dh * (i - left - 1);
            }
            st.push(i);
        }
        return ans;
    }
};

// @lc code=end
