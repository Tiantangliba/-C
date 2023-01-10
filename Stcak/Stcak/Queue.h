#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int size;
}Queue;


void QueueInit(Queue* q);// ��ʼ������ 
void QueuePush(Queue* q, QDataType data);// ��β����� 
void QueuePop(Queue* q);// ��ͷ������ 
QDataType QueueFront(Queue* q);// ��ȡ����ͷ��Ԫ�� 
QDataType QueueBack(Queue* q);// ��ȡ���ж�βԪ�� 
int QueueSize(Queue* q);// ��ȡ��������ЧԪ�ظ��� 
bool QueueEmpty(Queue* q);// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
void QueueDestroy(Queue* q);// ���ٶ��� 


