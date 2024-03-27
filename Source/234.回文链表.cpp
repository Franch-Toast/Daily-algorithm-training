// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem234.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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

using namespace std;
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (!(fast->next == nullptr || fast->next->next == nullptr))
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head; // 直接回到链表头
        slow = slow->next;
        /* 现在 slow 指向后半段的头节点，接下来对后半段进行反转 */
        ListNode * newhead = reverse(slow);
        // if(newhead == nullptr) return 0;
        while(newhead != nullptr)
        {
            if(newhead->val != fast->val) return 0;
            fast = fast->next;
            newhead = newhead->next;
        }
        return 1;
    }

    ListNode *reverse(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *newhead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;// 向上只返回新的头节点
    }


};
// @lc code=end
