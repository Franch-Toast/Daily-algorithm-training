/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

#include "vector"

using namespace std;
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *one = headA, *two = headB;
        while (1)
        {
            if (one == two)
                return one;
            one = one->next;
            two = two->next;
            if (one == nullptr && two == nullptr)
                break;
            if (one == nullptr)
                one = headB;
            if (two == nullptr)
                two = headA;
        }
        return NULL;
    }
};
// @lc code=end
