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

void SListPrint(SLTNode* phead);//打印
SLTNode* BuyListNode(SLTDataType x);//创建节点
void SListPushBack(SLTNode** pphead,SLTDataType x);//尾插
void SListPushFront(SLTNode** pphead, SLTDataType x);//头插
void SListPopBack(SLTNode** pphead);//尾删
void SListPopFront(SLTNode** pphead);//头删
SLTNode* SListFind(SLTNode* phead, SLTDataType x);//查找
//在pos位置之前插入一个节点,返回指针可以修改，插入
//单链表不适合在pos位置之前插入，因为他要判断是不是头插,时间复杂度O(n)
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SListInsertAfter(SLTNode* pos, SLTDataType x);//pos之后插入,时间复杂度O(1)
void SListErase(SLTNode** pphead, SLTNode* pos);//删除，时间复杂度O(n)
void SListEraseAfter(SLTNode* pos, SLTDataType x);//pos之后删除,时间复杂度O(1)

void SListDestroy(SLTNode** pphead);//销毁