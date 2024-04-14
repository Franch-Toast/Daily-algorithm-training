/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include "string"
#include "vector"

using namespace std;
class Solution {
public:
    vector<string> ans;
    string path;
    int left,right;
    vector<string> generateParenthesis(int n)
    {
        left = n;
        right = n;
        dfs();
        return ans;
    }

    void dfs(void)
    {
        if(left == 0 && right == 0) 
        {
            ans.push_back(path);
            return;
        }
        if(left) 
        {
            path.push_back('(');
            left--;
            dfs();
            path.pop_back();
            left++;
        }
        if (right && right > left)
        {
            path.push_back(')');
            right--;
            dfs();
            path.pop_back();
            right++;
        }
    }

};
// @lc code=end

