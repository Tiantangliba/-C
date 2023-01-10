#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);//��ӡ
SLTNode* BuyListNode(SLTDataType x);//�����ڵ�
void SListPushBack(SLTNode** pphead,SLTDataType x);//β��
void SListPushFront(SLTNode** pphead, SLTDataType x);//ͷ��
void SListPopBack(SLTNode** pphead);//βɾ
void SListPopFront(SLTNode** pphead);//ͷɾ
SLTNode* SListFind(SLTNode* phead, SLTDataType x);//����
//��posλ��֮ǰ����һ���ڵ�,����ָ������޸ģ�����
//�������ʺ���posλ��֮ǰ���룬��Ϊ��Ҫ�ж��ǲ���ͷ��,ʱ�临�Ӷ�O(n)
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SListInsertAfter(SLTNode* pos, SLTDataType x);//pos֮�����,ʱ�临�Ӷ�O(1)
void SListErase(SLTNode** pphead, SLTNode* pos);//ɾ����ʱ�临�Ӷ�O(n)
void SListEraseAfter(SLTNode* pos, SLTDataType x);//pos֮��ɾ��,ʱ�临�Ӷ�O(1)

void SListDestroy(SLTNode** pphead);//����