/*
 * @Author: Franch-Toast
 * @Date: 2024-02-18 11:47:01
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-02-18 11:55:27
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start

// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };

#include "vector"

using namespace std;
class Solution {
public:
    vector<int> ans;
    void dfs(Node *root)
    {
        for(Node *node : root->children)
        {
            if(node == nullptr) return;
            ans.push_back(node->val);
            dfs(node);
        }
        return;
    }


    vector<int> preorder(Node* root) {
        if(root == nullptr) return ans;
        else ans.push_back(root->val);
        dfs(root);
        return ans;
    }
};
// @lc code=end

