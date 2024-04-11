/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q) // 如果恰好root结点就是其中一个结点，那么公共祖先一定是上面的结点，直接返回即可
            return root;
        TreeNode *one = lowestCommonAncestor(root->left, p, q);  // 在左孩子搜索
        TreeNode *two = lowestCommonAncestor(root->right, p, q); // 在右孩子搜索
        if (one != nullptr && two != nullptr)
            return root;
        else if (one != nullptr)
            return one;
        else if (two != nullptr)
            return two;
        else
            return nullptr;
    }
};
// @lc code=end
