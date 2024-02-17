/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
#include "queue"

using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int cnt = q.size();
            vector<int> temp;
            while(cnt--)
            {
                Node *cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                for(Node *node : cur->children)
                {
                    q.push(node);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
// @lc code=end

