/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include "stack"
#include "vector"

using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n, -1); // 初始化索引为 -1
        stack<int> st;
        // 类似 739. 每日温度 的做法，从左向右遍历，找到第一个比当前元素小的位置
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[i] <= heights[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
            {
                left[i] = st.top();
            }
            st.push(i);
        }

        vector<int> right(n, n); // 初始化索引为 n
        st = stack<int>(); // 重置栈

        // 从右向左遍历，不断弹出栈顶，直到栈顶元素的大小比当前元素小
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[i] <= heights[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
            {
                right[i] = st.top();
            }
            st.push(i);
        }
        // 计算 以每一个元素作为高，计算宽（right - left）
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};

// @lc code=end
