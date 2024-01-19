/*
 * @Author: Franch-Toast
 * @Date: 2024-01-19 20:02:54
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-19 21:15:58
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
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
class Solution {
public:

    bool checkifdelete(TreeNode* root,int sum,int limit)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            if(sum + root->val < limit) return 0;
            else return 1;
        }
        bool left,right;
        if(root->left != nullptr) 
        {
            left = checkifdelete(root->left,sum + root->val,limit);
            if(!left) root->left = nullptr;
        }
        else left = 0;
        
        if(root->right != nullptr)
        {
            right = checkifdelete(root->right,sum + root->val,limit);
            if(!right) root->right = nullptr; 
        }
        else right = 0;
        
        return left | right;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(checkifdelete(root,0,limit))
            return root;
        else return nullptr;
    }
};
// @lc code=end

