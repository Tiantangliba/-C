#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int STDataType;
typedef struct Stack
{
	int _top;
	STDataType* _a;
	int _capacity;
}Stack;
void StackInit(Stack* ps);//��ʼ��ջ
void StackPush(Stack* ps, STDataType x);//��ջ
void StackDestroy(Stack* ps);//����ջ
void StackPop(Stack* ps);//��ջ
STDataType StackTop(Stack* ps);//��ȡջ��Ԫ��
int StackSize(Stack* ps);//��ȡջ��Ԫ�صĸ���
bool StackEmpty(Stack* ps);//���ջ�Ƿ�Ϊ��,�շ����棬�ǿշ��ؼ�