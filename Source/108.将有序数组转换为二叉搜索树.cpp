// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem108.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *dfs(vector<int> &nums,int start,int end)
    {
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        if(start <= mid-1)
            root->left = dfs(nums, start, mid - 1);
        // else root.left = nullptr;// 其实可以不需要，因为本身就是初始化的nullptr
        if(mid+1 <= end)
            root->right = dfs(nums, mid + 1, end);
        // else root.right = nullptr;
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return dfs(nums,0,nums.size()-1);
    }
};
// @lc code=end

