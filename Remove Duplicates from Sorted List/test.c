#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head == NULL)
        return head;
    struct ListNode* left = head;
    struct ListNode* right = head->next;
    while (right != NULL)
    {
        if (left->val == right->val)
        {
            right = right->next;
        }
        else
        {
            left->next = right;
            left = left->next;
            right = right->next;
        }
    }
    if (left->next != NULL && left->next->val == left->val)
    {
        left->next = NULL;
    }
    return head;
}