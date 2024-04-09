// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem114.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
// };

class Solution
{
public:
    /* https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solutions/17274/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--26/?envType=study-plan-v2&envId=top-100-liked */

    /* 方法一 */
    // void flatten(TreeNode* root) {
    //     if(root == nullptr) return;
    //     if(root->left == nullptr)
    //     {
    //         flatten(root->right);
    //         return;
    //     }
    //     TreeNode *right = root->right;
    //     root->right = root->left;
    //     root->left = nullptr;
    //     TreeNode *temp = root->right;
    //     while (temp->right != nullptr)
    //         temp = temp->right;
    //     temp->right = right;
    //     flatten(root->right);
    // }

    /* 方法二 */
    TreeNode *pre = nullptr;
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
};
// @lc code=end
