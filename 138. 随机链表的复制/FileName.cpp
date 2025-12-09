/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        Node* newrandom = nullptr;
        Node* newnode = nullptr;
        Node* pcur = head;
        Node* to;
        Node* newhead = (Node*)malloc(sizeof(Node));
        Node* last;
        newhead->next = nullptr;
        while (pcur)
        {
            to = pcur->next;
            Node* newone = (Node*)malloc(sizeof(Node));
            if (newhead->next == nullptr)
            {
                newhead->next = newone;
            }
            newone->next = nullptr;
            pcur->next = newone;
            newone->val = pcur->val;
            pcur = to;
            newone->next = pcur;
        }
        pcur = head;
        while (pcur && pcur->next)
        {
            if (pcur->random != nullptr)
            {
                pcur->next->random = pcur->random->next;
            }
            else
            {
                pcur->next->random = nullptr;
            }
            pcur = pcur->next->next;//现在已经在有效元素上了
        }
        pcur = head;
        while (pcur && pcur->next)
        {
            last = pcur;
            pcur = pcur->next;
            to = pcur->next;
            if (to)
            {
                pcur->next = to->next;
            }
            else
            {
                pcur->next = nullptr;
            }
            pcur = to;
            last->next = to;
        }

        return newhead->next;
    }
};