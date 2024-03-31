/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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

using namespace std;
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
    /* 递归归并排序 */
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        /* 找到中点切开 */
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 获取到了两段链表
        ListNode *temp = slow->next;
        slow->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(temp);

        ListNode *ptr = new ListNode(0);
        ListNode *newhead = ptr;

        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                ptr->next = left;
                left = left->next;
            }
            else
            {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        ptr->next = left == nullptr ? right : left;
        return newhead->next;
    }
};
// @lc code=end
