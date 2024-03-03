// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem106.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start
//  Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include "vector"
#include "unordered_map"

using namespace std;
class Solution {
public:
    unordered_map<int,int> couple;
    vector<int> rootorder;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        rootorder = postorder;
        for(int i = 0; i < inorder.size(); i++)
            couple[inorder[i]] = i;
        return dfs(postorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *dfs(int root_pos, int start, int end)
    {
        if(start > end) return nullptr;
        TreeNode *node = new TreeNode(rootorder[root_pos]);
        int pos = couple[rootorder[root_pos]];
        node->left = dfs(root_pos - (end - pos) - 1, start, pos - 1);
        node->right = dfs(root_pos - 1, pos + 1, end);
        return node;
    }
};
// @lc code=end

