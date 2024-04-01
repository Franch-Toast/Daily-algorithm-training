/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return 1;
        else if (left == NULL || right == NULL)
            return 0;
        else if (left->val != right->val)
            return 0;
        else
            return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};
// @lc code=end
