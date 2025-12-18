typedef struct ListNode ListNode;
typedef struct ListNode ListNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // 创建一个哨兵节点（dummy head），简化链表插入操作
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    ListNode* curr = dummy;
    int carry = 0; // 进位

    // 当 l1 或 l2 还有节点，或者还有进位时，继续循环
    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        // 如果 l1 不为空，加上 l1 的值，并移动 l1 指针
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        // 如果 l2 不为空，加上 l2 的值，并移动 l2 指针
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        // 计算进位
        carry = sum / 10;

        // 创建新节点，存储当前位的值
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        // 将新节点连接到结果链表
        curr->next = newNode;
        curr = newNode;
    }

    // 返回真正的头节点（跳过哨兵节点）
    ListNode* result = dummy->next;
    free(dummy); // 释放哨兵节点，或者根据题目要求不释放（视具体环境而定，通常LeetCode不需要手动释放）
    return result;
}