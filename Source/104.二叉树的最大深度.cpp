/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

#include "vector"
using namespace std;
class Solution {
public:
    int ans = 0;
    int maxDepth(TreeNode* root) {
        nextDepth(root, 0);
        return ans;
    }
    void nextDepth(TreeNode *root,int depth)
    {
        if(root == nullptr) return;

        depth += 1;
        ans = max(ans,depth);
        nextDepth(root->left, depth);
        nextDepth(root->right, depth);
    }
};
// @lc code=end

