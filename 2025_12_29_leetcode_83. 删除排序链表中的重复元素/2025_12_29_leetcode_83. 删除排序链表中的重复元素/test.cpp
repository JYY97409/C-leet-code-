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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* newhead = nullptr;
        ListNode* Newtail = nullptr;
        while (cur)
        {
            if (Newtail && Newtail->val == cur->val)
            {
                cur = cur->next;
                continue;
            }
            ListNode* NewNode = new ListNode();
            NewNode->val = cur->val;
            NewNode->next = nullptr;
            if (newhead == nullptr)
            {
                newhead = NewNode;
                Newtail = NewNode;
            }
            else
            {
                Newtail->next = NewNode;
                Newtail = NewNode;
            }
        }
        return newhead;
    }
};


//



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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* cur = head;
        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
};