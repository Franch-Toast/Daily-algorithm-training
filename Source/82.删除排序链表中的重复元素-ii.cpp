/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *guard = new ListNode(0,head);
        ListNode *pre = guard;
        // 防止是个空链表。终止条件是后续无结点了
        while(head != nullptr && head->next != nullptr)
        {
            if(head->val == head->next->val)
            {
                int temp = head->val;
                while(head != nullptr && head->val == temp)
                    head = head->next;
                pre->next = head;
            }
            else 
            {
                head = head->next;
                pre = pre->next;
            }
        }
        return guard->next;
    }
};
// @lc code=end

