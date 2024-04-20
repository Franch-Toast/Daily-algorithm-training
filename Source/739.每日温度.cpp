/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include "vector"
#include "stack"
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;





        /* 方法一：从左向右遍历，将没有获取到答案的日子放入栈中，栈中元素从栈底到栈顶是递减的 */
        // for(int i = 0; i < n; i++){
        //     // 找到了比栈顶元素大的新元素，则直接计算栈顶元素，直到栈顶元素比当前元素大
        //     while (!st.empty() && temperatures[i] > temperatures[st.top()])
        //     {
        //         int previousIndex = st.top();
        //         ans[previousIndex] = i - previousIndex;
        //         st.pop();
        //     }
        //     // 当前的元素还没有计算过，入栈
        //     st.push(i);
        // }
        // return ans;


        /* 方法二：从右向左遍历，将已经获取到答案的日子放入栈中，栈中元素从栈底到栈顶是递减的 */
        for(int i = n-1;i >= 0;i--)
        {
            // 如果出现了一个新的日子比栈顶元素大(或相等)，那么栈顶元素就没用了，因为有当前日子来起作用，那么栈顶元素就可以直接出栈了
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }
            // 现在栈顶的元素一定比新的日子要大，或者栈为空
            if(!st.empty())
            {
                ans[i] = st.top() - i;
            }
            // 初始化为0，所以对于空栈不用做操作（即为自身）
            st.push(i);
        }

        return ans;
    }
};
// @lc code=end

