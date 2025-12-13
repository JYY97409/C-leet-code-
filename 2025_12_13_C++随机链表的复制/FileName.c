class Solution {
public:
    Node* copyRandomList(Node* head)
    {

        class Node* newhead = (class Node*)malloc(sizeof(class Node));
        newhead->next = nullptr;
        class Node* cur = head;
        class Node* next = nullptr;
        class Node* copy = nullptr;
        while (cur)
        {
            next = cur->next;//提前找到下一个节点
            Node* newnode = (Node*)malloc(sizeof(Node));
            newnode->val = cur->val;
            newnode->next = nullptr;
            //细节置空，防止在最后一个节点的边界条件上栽跟头
            if (nullptr == newhead->next)
            {
                //先判空
                newhead->next = newnode;
            }
            cur->next = newnode;//将newnode挂在原链表上
            newnode->next = next;
            cur = next;
        }
        cur = head;
        while (cur)//这里因为从逻辑上来说cur为真的话cur->next肯定也为真所以不用验证cur->next
        {
            next = cur->next;
            if (nullptr == cur->random)
            {
                //先判空
                next->random = nullptr;
            }
            else
            {
                //通过原链表来找到复制节点
                next->random = cur->random->next;
                //每一个节点的复制节点都在它的下一个
            }
            cur = next->next;
        }
        cur = head;
        while (cur)//这里因为从逻辑上来说cur为真的话cur->next肯定也为真所以不用验证cur->next
        {
            copy = cur->next;
            next = copy->next;
            if (nullptr == next)
            {
                //验证最后一个节点的边界情况
                copy->next = nullptr;
            }
            else
            {
                copy->next = next->next;
            }
            cur->next = next;
            cur = next;
        }
        return newhead->next;
    }
};