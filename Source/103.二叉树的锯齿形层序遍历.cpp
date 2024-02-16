/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
#include "queue"

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        q.push(root);
        bool direct = 1;
        while(!q.empty())
        {
            int cnt = q.size();
            vector<int> temp;
            while(cnt--)
            {
                TreeNode* front_node = q.front();
                q.pop();
                if(direct)
                    temp.push_back(front_node->val);
                else temp.insert(temp.begin(),front_node->val);

                if(front_node->left != nullptr) q.push(front_node->left);
                if(front_node->right != nullptr) q.push(front_node->right);
            
            }
            ans.push_back(temp);
            direct = !direct;
        }
        return ans;
    }
};
// @lc code=end

