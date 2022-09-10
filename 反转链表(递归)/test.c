#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        struct ListNode* ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }

}