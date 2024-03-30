/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int total = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
            total++;
        }
        total -= n;
        ListNode *fakehead = new ListNode(-1,head);
        temp = fakehead;
        while(total--)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return fakehead->next;
    }
};
// @lc code=end
