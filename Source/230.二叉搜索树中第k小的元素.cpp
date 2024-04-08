/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
#include "stack"
using namespace std;
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> s;
        TreeNode *cur = root;

        /* 先按中序遍历的顺序入栈 */
        while (cur != nullptr || s.size() > 0)
        {
            while (cur != nullptr) // 一路将结点及左孩子结点入栈
            {
                s.push(cur);
                cur = cur->left;
            }
            // 到这里说明没有左孩子了，获取栈顶元素来处理
            cur = s.top(); // 获取栈顶元素
            s.pop();
            if (k-- == 1)// 计数
                break;
            cur = cur->right; // 接下来向右孩子结点找
        }
        return cur->val;
    }
};
// @lc code=end
