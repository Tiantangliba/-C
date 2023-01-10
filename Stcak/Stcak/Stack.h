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
void StackInit(Stack* ps);//初始化栈
void StackPush(Stack* ps, STDataType x);//入栈
void StackDestroy(Stack* ps);//销毁栈
void StackPop(Stack* ps);//出栈
STDataType StackTop(Stack* ps);//获取栈顶元素
int StackSize(Stack* ps);//获取栈中元素的个数
bool StackEmpty(Stack* ps);//检测栈是否为空,空返回真，非空返回假