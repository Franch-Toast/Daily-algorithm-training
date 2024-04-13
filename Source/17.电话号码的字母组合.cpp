/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include "vector"
#include "string"

using namespace std;
class Solution
{
public:
    vector<string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string path;
    vector<string> letterCombinations(string digits)
    {
        if(digits.size() == 0) return ans;
        dfs(digits, 0);
        return ans;
    }

    void dfs(string digits, int index)
    {
        if (path.size() == digits.size())
        {
            ans.push_back(path);
            return;
        }

        int num = digits[index] - '0';
        for (int j = 0; j < board[num].size(); j++)
        {
            path.push_back(board[num][j]);
            dfs(digits, index + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
