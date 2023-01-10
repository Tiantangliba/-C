#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int size;
}Queue;


void QueueInit(Queue* q);// 初始化队列 
void QueuePush(Queue* q, QDataType data);// 队尾入队列 
void QueuePop(Queue* q);// 队头出队列 
QDataType QueueFront(Queue* q);// 获取队列头部元素 
QDataType QueueBack(Queue* q);// 获取队列队尾元素 
int QueueSize(Queue* q);// 获取队列中有效元素个数 
bool QueueEmpty(Queue* q);// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
void QueueDestroy(Queue* q);// 销毁队列 


