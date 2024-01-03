
/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include "stack"

using namespace std;
class Solution {
public:
    // 使用栈的方法
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode *> st;
        while(head->next != nullptr)
        {
            st.push(head);
            head = head->next;
        }
        // 现在head指向的最后一个链表元素
        while(st.size() != 0)
        {
            if(st.top()->val >= head->val)
            // 如果栈顶元素的val >= 新链表表头元素的val，则加入新链表，然后弹出
            {
                st.top()->next = head;
                head = st.top();
            }
            st.pop();
        }
        return head;
    }

    // 使用递归的方法，返回值为后续的链表的第一个节点，同时也意味着是最大的数
    ListNode* removeNodes_method2(ListNode* head) {
        if(head->next == nullptr) return head;
        ListNode *next_max = removeNodes_method2(head->next);
        if(head->val < next_max->val) return next_max;
        head->next = next_max;
        return head;
    }

};
// @lc code=end

