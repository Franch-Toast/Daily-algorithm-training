/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr)
            return head;
        ListNode *newhead = head;
        for(int i = 1; i <= k ; i++)
        {
            if (newhead->next != nullptr)
                newhead = newhead->next;
            else{
                newhead = head;
            }
        }
        ListNode *tail = head;
        while (newhead->next != nullptr)
        {
            tail = tail -> next;
            newhead = newhead->next;
        }

        
        newhead->next = head;
        newhead = tail->next;
        tail->next = nullptr;
        return newhead;
    }
};
// @lc code=end

