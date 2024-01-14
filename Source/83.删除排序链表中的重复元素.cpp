// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem83.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
        ListNode *guard = head;// 提前准备指针
        while (head != NULL && head->next != NULL)
        {
            if(head->next->val == head->val)
            {
                head->next = head->next->next; 
                // 注意如果发生了重复，则指针不要移动，查看是否还有重复的
            }
            else head = head->next;
            // 如果没有发生重复，则指针移动
        }
        return guard;
    }
};
// @lc code=end

