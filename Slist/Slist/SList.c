#include"SList.h"
void SListPrint(SLTNode* phead)//��ӡ
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

SLTNode* BuyListNode(SLTDataType x)//�����ڵ�
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPushBack(SLTNode** pphead,SLTDataType x)//β��
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

void SListPushFront(SLTNode** pphead, SLTDataType x)//ͷ��
{
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead)//βɾ
{
	assert(pphead);
	assert(*pphead);//�޽ڵ�����
	if ((*pphead)->next == NULL)//ֻ��һ���ڵ�
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//�����������ڵ����ϵ����
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

void SListPopFront(SLTNode** pphead)//ͷɾ
{
	assert(pphead);
	assert(*pphead);//�޽ڵ�
	SLTNode* cur = (*pphead)->next;
	free(*pphead);
	*pphead = cur;
}
SLTNode* SListFind(SLTNode* phead, SLTDataType x)//����
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

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)//posָ��λ��ǰ����
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

void SListInsertAfter(SLTNode* pos, SLTDataType x)//pos֮�����
{
	assert(pos);
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListErase(SLTNode** pphead, SLTNode* pos)//ɾ��
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

void SListEraseAfter(SLTNode* pos, SLTDataType x)//pos֮��ɾ��,ʱ�临�Ӷ�O(1)
{
	assert(pos->next);
	SLTNode* cur = pos->next;
	pos->next = cur->next;
	free(cur);
}

void SListDestroy(SLTNode** pphead)//����
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
