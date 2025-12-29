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
ListNode* GetMidNode(ListNode* head)
{
    ListNode* left = head;
    ListNode* right = head;
    while (right && right->next)
    {
        left = left->next;
        right = right->next->next;
    }
    return left;
}
ListNode* SwapList(ListNode* head)
{
    ListNode* right = head->next;
    ListNode* left = head;
    ListNode* next = nullptr;
    while (left->next)
    {
        next = right->next;
        right->next = left;
        left = right;
        if (next)
            right = next;
        else
            break;
    }
    head->next = nullptr;
    return left;
}
class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        if (nullptr == head)
            return true;
        if (nullptr != head && nullptr == head->next)
            return true;
        ListNode* mid = GetMidNode(head);
        ListNode* newhead = SwapList(mid);
        ListNode* left = newhead;
        ListNode* right = head;
        while (left && right)
        {
            if (left->val != right->val)
                return false;

            left = left->next;
            right = right->next;
        }
        return true;
    }
};