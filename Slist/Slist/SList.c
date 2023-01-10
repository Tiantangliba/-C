#include"SList.h"
void SListPrint(SLTNode* phead)//打印
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

SLTNode* BuyListNode(SLTDataType x)//创建节点
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPushBack(SLTNode** pphead,SLTDataType x)//尾插
{
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)//头插
{
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead)//尾删
{
	assert(pphead);
	assert(*pphead);//无节点的情况
	if ((*pphead)->next == NULL)//只有一个节点
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//两个及两个节点以上的情况
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SListPopFront(SLTNode** pphead)//头删
{
	assert(pphead);
	assert(*pphead);//无节点
	SLTNode* cur = (*pphead)->next;
	free(*pphead);
	*pphead = cur;
}
SLTNode* SListFind(SLTNode* phead, SLTDataType x)//查找
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
	}
	return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)//pos指针位置前插入
{
	assert(pos);
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)//pos之后插入
{
	assert(pos);
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListErase(SLTNode** pphead, SLTNode* pos)//删除
{
	assert(pphead);
	assert(*pphead);
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

void SListEraseAfter(SLTNode* pos, SLTDataType x)//pos之后删除,时间复杂度O(1)
{
	assert(pos->next);
	SLTNode* cur = pos->next;
	pos->next = cur->next;
	free(cur);
}

void SListDestroy(SLTNode** pphead)//销毁
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}
