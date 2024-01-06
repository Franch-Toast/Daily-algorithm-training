/*
 * @lc app=leetcode.cn id=2807 lang=cpp
 *
 * [2807] 在链表中插入最大公约数
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
#include "math.h"
class Solution {
public:
    // ListNode *getmiddlenode(ListNode *left, ListNode *right)
    // {
    //     int ans = 1;
    //     int temp = min(left->val, right->val);
    //     for (int i = 1; i <= (int)sqrt(temp); i++)
    //     {
    //         if(temp % i == 0)
    //         {
    //             if (left->val % i == 0 && right->val % i == 0) 
    //                 ans = max(ans,i);
    //             if (left->val % (temp / i) == 0 && right->val % (temp / i) == 0)
    //                 ans = max(ans, (temp / i));
    //         }
    //     }
    //     ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    //     newnode->val = ans;
    //     newnode->next = right;
    //     return newnode;
    // }


    // 辗转相除法求最大公约数
    ListNode *getmiddlenode(ListNode *left, ListNode *right)
    {
        int small = min(left->val,right->val);
        int big = left->val + right->val - small;
        while(small != 0)
        {
            int temp = big % small;
            big = small;
            small = temp;
        }
        ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
        newnode->val = big;
        newnode->next = right;
        return newnode;
    }

    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *newhead = head;
        while (head->next != NULL)
        {
            head->next = getmiddlenode(head,head->next);
            head = head->next->next;
        }
        return newhead;
    }
};
// @lc code=end

