/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * */
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode *> qu;
        qu.emplace(root);
        bool isOdd = false;
        while (!qu.empty()) {
            int sz = qu.size();// 获取上一层的节点数量，作为这一层的循环次数的依仗
            vector<TreeNode *> arr;
            for (int i = 0; i < sz; i++) {
                TreeNode *node = qu.front();
                qu.pop();
                if (isOdd) {
                    arr.emplace_back(node);// 如果该层是奇数层，则把该节点加入到数组中
                }
                if (node->left) {// 如果不是叶子节点，将该节点的左右孩子加入队列，这里其实保证了下一层的顺序不会出现问题
                    qu.emplace(node->left);
                    qu.emplace(node->right);
                }
            }
            if (isOdd) {// 如果这一层是奇数层
                for (int l = 0, r = sz - 1; l < r; l++, r--) {// 精髓在此处：此前保存了该层sz个节点的值，只需要使用双指针交换两个节点的值即可
                    swap(arr[l]->val, arr[r]->val);
                    // 很重要的一点！arr中保存的一定得是节点，这样通过swap进行交换的才能是节点中的数据，如果保存的是数值，则对节点本身没有任何影响！
                }
            }            
            isOdd ^= true;
        }
        return root;
    }
};

// @lc code=end

