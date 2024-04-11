/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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

class Solution
{
public:
    /* 以root结点作为起点，返回路径和与targetsum相等的次数 */
    int rootSum(TreeNode *root, long long targetSum)
    {
        if (!root)
        {
            return 0;
        }

        int ret = 0;
        if (root->val == targetSum)
        {
            ret++;
        }

        ret += rootSum(root->left, targetSum - root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;
    }

    /* 以root为根节点，子树中有多少个路径和为targetsum的路径，但是实际上只判断当前节点为起点的路径，其他的通过递归实现 */
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return 0;
        }

        int ret = rootSum(root, targetSum);// 获取以root为起点的路径满足条件的数量
        ret += pathSum(root->left, targetSum);// 递归，判断左子树有多少个
        ret += pathSum(root->right, targetSum); // 递归，判断右子树有多少个
        return ret;
    }
};

// @lc code=end
