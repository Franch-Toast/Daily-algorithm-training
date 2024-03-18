/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode *sortInList(ListNode *head)
    {
        // write code here
        if (head == nullptr || head->next == nullptr)
            return head;

        // 查找链表的中点以分割链表
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 将两段链表拆开，temp作为第二段链表的头指针
        ListNode *temp = slow->next;
        slow->next =
            nullptr; // 记得将第一段链表的为指针标记为nullptr，否则不是链表的结尾

        // 递归，并返回其头节点
        ListNode *left = sortInList(head);
        ListNode *right = sortInList(temp);

        ListNode *ans = new ListNode(0);
        ListNode *res = ans;
        while (left != nullptr && right != nullptr)
        {
            if (left->val > right->val)
            {
                ans->next = right;
                right = right->next;
            }
            else
            {
                ans->next = left;
                left = left->next;
            }
            ans = ans->next;
        }
        if (left == nullptr)
            ans->next = right;
        else
            ans->next = left;
        return res->next;
    }
};