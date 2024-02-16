/*
 * @Author: Franch-Toast
 * @Date: 2024-02-08 11:01:01
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-02-08 11:46:50
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
// #include "unordered_map"
// #include "stack"

// using namespace std;
class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        int depth = 0;
        TreeNode *father = nullptr;
        function<bool(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode *node, TreeNode *fa, int d) -> bool {
            if (node == nullptr) {
                return false;
            }
            if (node->val == x || node->val == y) { // 找到 x 或 y
                if (depth) { // 之前已找到 x y 其中一个
                    return depth == d && father != fa;
                }
                depth = d; // 之前没找到，记录信息
                father = fa;
            }
            return dfs(node->left, node, d + 1) || dfs(node->right, node, d + 1);
        };
        return dfs(root, nullptr, 1);
    }
};

// @lc code=end

