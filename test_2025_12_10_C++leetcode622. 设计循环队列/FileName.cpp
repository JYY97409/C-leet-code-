struct Node
{
    int val;
    int flag;
    struct Node* next;
};
class MyCircularQueue
{
private:

    struct Node* head;
    struct Node* tail;
    int size;

public:
    MyCircularQueue(int k)
    {
        if (k > 1)
        {
            Node* newnode = (Node*)malloc(sizeof(Node));
            tail = newnode;
            head = newnode;
            newnode->flag = 0;//代表为空
            tail->next = nullptr;
            head->next = nullptr;
            for (int i = 1; i < k; i++)
            {
                Node* newnode = (Node*)malloc(sizeof(Node));
                newnode->flag = 0;//代表为空
                if (nullptr == head)
                {
                    head = newnode;
                    tail = newnode;
                }
                else
                {
                    tail->next = newnode;
                    tail = newnode;
                }
            }
            tail->next = head;
            tail = head;
        }
        if (k == 1)
        {
            Node* newnode = (Node*)malloc(sizeof(Node));
            tail = newnode;
            head = newnode;
            tail->next = nullptr;
            head->next = nullptr;
            tail->next = head;
        }

    }

    bool enQueue(int value)
    {
        Node* cur = head;
        if (head == tail && head->flag == 1)
        {
            return false;
        }
        else
        {
            tail->val = value;
            tail->flag = 1;
            tail = tail->next;
            return true;

        }
        return false;
    }

    bool deQueue()
    {
        if (head->flag == 0)
        {
            return false;
        }
        else
        {
            head->flag = 0;
            head = head->next;
            return true;
        }
    }

    int Front()
    {
        if (0 == head->flag)
        {
            return -1;
        }
        else
        {
            return head->val;
        }
    }

    int Rear()
    {
        if (head->flag == 0)
        {
            return -1;
        }
        Node* cur = head;
        while (cur->next != tail)
        {
            cur = cur->next;
        }
        if (cur->flag != 0)
        {
            return cur->val;
        }
        else
        {
            return -1;
        }
    }

    bool isEmpty()
    {
        Node* cur = head;
        if (cur->flag != 0)
        {
            return false;
        }
        cur = cur->next;
        while (cur != head)
        {
            if (cur->flag != 0)
            {
                return false;
            }
            cur = cur->next;
        }
        return true;
    }

    bool isFull()
    {
        Node* cur = head;
        if (cur->flag == 0)
        {
            return false;
        }
        cur = cur->next;
        while (cur != head)
        {
            if (cur->flag == 0)
            {
                return false;
            }
            cur = cur->next;
        }
        return true;
    }
};