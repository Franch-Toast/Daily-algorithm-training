/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include "unordered_map"
using namespace std;

// class Node
// {
// public:
//     int val;
//     Node *next;
//     Node *random;

//     Node(int _val)
//     {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

class Solution {
public:
    unordered_map<Node *, Node *> cachedNode;
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(!cachedNode.count(head))
        {
            Node* newhead = new Node(head->val);
            cachedNode[head] = newhead; 
            // 表明head已经拷贝过了，为newhead，并将对应新创建的结点加入哈希表，下次可以直接使用
            newhead->next = copyRandomList(head->next); // 递归获取后面的结点的拷贝指针
            newhead->random = copyRandomList(head->random);
        }
        return cachedNode[head];// 返回该结点的拷贝结点，前面已经创建了
    }
};
// @lc code=end

