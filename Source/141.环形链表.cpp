/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;


// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr){}                             
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head,*fast = head;
        if(head == nullptr) return 0;
        while (fast->next != nullptr && fast->next->next!= nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return 1;
        }
        return 0;
    }
};
// @lc code=end

