// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem155.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include "stack"
#include "vector"
using namespace std;
class MinStack
{
public:
    vector<int> st;
    stack<int> temp;
    stack<int> min_obj;
    MinStack()
    {
        
    }

    void push(int val)
    {
        st.push_back(val);

        if (st.size() == 0)
            min_obj.push(val);
        else
        {
            while (min_obj.size() > 0 && min_obj.top() < val)
            {
                temp.push(min_obj.top());
                min_obj.pop();
            }
            min_obj.push(val);
            while (temp.size() != 0)
            {
                min_obj.push(temp.top());
                temp.pop();
            }
        }
    }

    void pop()
    {
        int val = top();
        st.pop_back();

        while (min_obj.size() > 0 && min_obj.top() != val)
        {
            temp.push(min_obj.top());
            min_obj.pop();
        }
        min_obj.pop();
        while (temp.size() != 0)
        {
            min_obj.push(temp.top());
            temp.pop();
        }
    }

    int top()
    {
        return st[st.size() - 1];
    }

    int getMin()
    {
        return min_obj.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
