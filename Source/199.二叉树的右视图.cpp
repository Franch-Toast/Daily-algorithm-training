/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include "queue"
#include "vector"
using namespace std;
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if(root == nullptr) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int cnt = q.size();
            while(cnt--)
            {
                TreeNode *temp = q.front();
                q.pop();
                if(cnt == 0) ans.push_back(temp->val);
                if(temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};
// @lc code=end
