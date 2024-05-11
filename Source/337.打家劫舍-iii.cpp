/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include "vector"

using namespace std;
class Solution
{
public:
    vector<int> robTreeNode(TreeNode *cur)
    {
        // 返回的vector<int> dp(2); 其中 dp[0]表示该结点不偷时的最高金额，dp[1]表示该结点偷时的最高金额
        if (cur == nullptr)
            return {0, 0}; // 如果为空指针，那么不管偷不偷都一定是0

        int val1 = 0, val2 = cur->val;

        vector<int> left = robTreeNode(cur->left);

        vector<int> right = robTreeNode(cur->right);
        // 如果偷这个节点，那么左右结点一定不能偷
        val2 += right[0] + left[0];
        // 如果不透这个节点，那么左右结点可偷可不偷，做最大值判断
        val1 += max(left[0], left[1]) + max(right[0], right[1]);

        return {val1,val2};
    }

    int rob(TreeNode *root)
    {
        vector<int> dp = robTreeNode(root);
        return max(dp[0],dp[1]);
    }
};
// @lc code=end
