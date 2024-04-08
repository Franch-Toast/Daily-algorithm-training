/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    /* 重要的内容是，如果每个结点都满足二叉搜索树，那么整棵树一定就是二叉搜索树，这就意味着只要遍历一个结点的左中右，判断当前节点是否比上一个结点大即可（递增） */

    /* 除了使用递归来做之外，这题也可以使用 栈 来完成，类似层序遍历（用的是队列），同样要有一个pre指针来记录 */
    TreeNode *pre = nullptr; // 用来记录前一个遍历的结点
    bool isValidBST(TreeNode *root)
    {
        if(root == nullptr) return 1;// 叶子结点直接返回true
        bool left = isValidBST(root->left);// 判断左孩子是否满足

        if(pre != nullptr && pre->val >= root->val) return 0; // 判断自己是否满足
        pre = root;// 自己已经判断完了，让自己作为前一个结点给别人判断

        bool right = isValidBST(root->right); // 判断右孩子是否满足
        return left && right;// 返回结果
    }
};
// @lc code=end
