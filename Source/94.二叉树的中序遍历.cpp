/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include "vector"
using namespace std;

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
    vector<int> Tree;
    vector<int> inorderTraversal(TreeNode *root)
    {
        dfs(root);
        return Tree;
    }

    void dfs(TreeNode *root)
    {
        /* 添加了对空指针的判断后可以不需要做叶子结点的判断了 */
        if (root == nullptr) 
            return ;

        // if ((root->left == nullptr && root->right == nullptr)) 
        // {
        //     Tree.push_back(root->val);
        //     return;
        // }

        dfs(root->left);// 如果是叶子结点，则直接会返回
        Tree.push_back(root->val);
        dfs(root->right);
        return;
    }

};
// @lc code=end
