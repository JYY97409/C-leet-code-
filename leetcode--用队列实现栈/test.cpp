#include<iostream>

typedef int NodeType;

struct Queuenode
{
	int x;
	Queuenode* next;
};

struct Queue
{
	Queuenode* phead;
	Queuenode* ptail;
	int size = 0;
};

Queue* QueueInit()
{
	Queue* qt = (Queue*)malloc(sizeof(Queue));
	if (qt == nullptr)
	{
		perror("Init");
		return nullptr;
	}
	qt->phead = nullptr;
	qt->ptail = nullptr;
	qt->size = 0;
	return qt;
}

void QueueAdd(Queue* qt, NodeType x)
{
	Queuenode* newnode = (Queuenode*)malloc(sizeof(Queuenode));
	if (nullptr == newnode)
	{
		perror("malloc");
		return;
	}
	newnode->next = nullptr;
	if (nullptr == newnode)
	{
		perror("malloc");
		return;
	}
	if (nullptr == qt->phead && nullptr == qt->ptail)
	{
		qt->phead = newnode;
		qt->ptail = newnode;
	}
	else
	{
		qt->ptail->next = newnode;
		qt->ptail = newnode;
	}
	newnode->x = x;
	qt->size++;
}

NodeType QueuePop(Queue* qt)
{
	NodeType ret = -1;
	if (nullptr == qt || nullptr == qt->phead)
	{
		std::cout << "还没有存储数据，无法删除" << std::endl;
		return -1;
	}
	if (nullptr == qt->phead->next)
	{
		ret = qt->phead->x;
		free(qt->phead);
		qt->phead = nullptr;
		qt->ptail = nullptr;
	}
	else
	{
		ret = qt->phead->x;
		Queuenode* next = qt->phead->next;
		free(qt->phead);
		qt->phead = next;
	}
	qt->size--;
	return ret;
}

int Queuesize(Queue* qt)
{
	return qt->size;
}

NodeType QueueFront(Queue* qt)
{
	assert(qt);
	if (nullptr == qt && nullptr == qt->phead)
	{
		std::cout << "没有存入数据，无法读取" << std::endl;
		return -1;
	}

	return qt->phead->x;
}

NodeType QueueTail(Queue* qt)
{
	assert(qt);
	if (nullptr == qt->phead)
	{
		std::cout << "没有存入数据，无法读取" << std::endl;
		return -1;
	}
	return qt->ptail->x;
}

void QueueDisplayFront(Queue* qt)
{
	if (nullptr == qt)
	{
		std::cout << "没有存入数据，无法读取" << std::endl;
		return;
	}
	Queuenode* pcur = qt->phead;
	while (pcur)
	{
		std::cout << pcur->x << "  ";
		pcur = pcur->next;
	}
	std::cout << std::endl;
}

void QueueDestory(Queue*& qt)
{
	if (nullptr == qt)
	{
		std::cout << "队列为空，无需删除" << std::endl;
		return;
	}
	else if (nullptr == qt->phead)
	{
		std::cout << "队列为空，无需删除" << std::endl;
		return;
	}

	Queuenode* next = nullptr;
	Queuenode* pcur = qt->phead;
	while (pcur)
	{
		next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(qt);
	qt = nullptr;
}

class MyStack {
private:
	Queue* qt1;
	Queue* qt2;
public:

	MyStack()
	{
		qt1 = QueueInit();
		qt2 = QueueInit();
	}

	void push(int x)
	{
		if (nullptr == qt1 && nullptr == qt2)
		{
			QueueAdd(qt1, x);
		}
		else
		{
			Queue* empty = qt1;
			Queue* unempty = qt2;
			if (nullptr == qt2->phead)
			{
				empty = qt2;
				unempty = qt1;
			}
			QueueAdd(unempty, x);
		}
	}

	int pop()
	{
		Queue* empty = qt1;
		Queue* unempty = qt2;
		if (nullptr == qt2->phead)
		{
			empty = qt2;
			unempty = qt1;
		}
		while (Queuesize(unempty) > 1)
		{
			NodeType x = QueuePop(unempty);
			QueueAdd(empty, x);
		}
		return QueuePop(unempty);
	}

	int top()
	{
		Queue* empty = qt1;
		Queue* unempty = qt2;
		if (nullptr == qt2->phead)
		{
			empty = qt2;
			unempty = qt1;
		}
		return QueueTail(unempty);
	}

	bool empty()
	{
		if (nullptr == qt1->phead && nullptr == qt2->phead)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */