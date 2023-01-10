#include"List.h"
ListNode* ListCreate()// �������������ͷ���
{
	ListNode* pHead = (ListNode*) malloc(sizeof(ListNode));
	pHead->_next =pHead;
	pHead->_prev = pHead;
	return pHead;
}


void ListPushBack(ListNode* pHead, LTDataType x)// ˫������β��
{
	assert(pHead);
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	ListNode* tail = pHead->_prev;
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = pHead;
	pHead->_prev = newnode;
}


void ListPrint(ListNode* pHead)// ˫�������ӡ
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d  ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void ListPopBack(ListNode* pHead)// ˫������βɾ
{
	assert(pHead);
	assert(pHead->_next!=pHead);
	ListNode* cur = pHead->_prev;
	ListNode* prev = cur->_prev;
	prev->_next = pHead;
	pHead->_prev = prev;
	free(cur);
}


void ListPushFront(ListNode* pHead, LTDataType x)// ˫������ͷ��
{
	assert(pHead);
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	ListNode* head = pHead->_next;//��¼һ��������ͷ�ڵ㣬���Ӹ���
	newnode->_next = head;
	head->_prev = newnode;
	newnode->_prev = pHead;
	pHead->_next = newnode;
}


void ListPopFront(ListNode* pHead)// ˫������ͷɾ
{
	assert(pHead);
	assert(pHead->_next != pHead);
	ListNode* head = pHead->_next;
	ListNode* headnext = head->_next;
	pHead->_next = headnext;
	headnext->_prev = pHead;
	free(head);
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)// ˫���������
{
	ListNode* find = pHead->_next;
	while (find != pHead)
	{
		if (find->_data == x)
			return find;
		else
			find = find->_next;
	}
	return NULL;
}


void ListInsert(ListNode* pos, LTDataType x)// ˫��������pos��ǰ����в���
{
	assert(pos);
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	ListNode* posPrev = pos->_prev;
	newnode->_next = pos;
	pos->_prev = newnode;
	newnode->_prev = posPrev;
	posPrev->_next = newnode;
}


void ListErase(ListNode* pos)// ˫������ɾ��posλ�õĽڵ�
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}