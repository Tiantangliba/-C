#include"Stack.h"

void StackInit(Stack* ps)//初始化栈
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)//入栈
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : (ps->_capacity) * 2;
		STDataType* tmp = realloc(ps->_a, sizeof(STDataType)*newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->_a = tmp;
		ps->_capacity = newcapacity;
	}

	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackDestroy(Stack* ps)//销毁栈
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackPop(Stack* ps)//出栈
{
	assert(ps);
	assert(ps->_top > 0);
	ps->_top--;
}

STDataType StackTop(Stack* ps)//获取栈顶元素
{
	assert(ps);
	assert(ps->_top > 0);
	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)//获取栈中元素的个数
{
	assert(ps);
	return ps->_top;
}

bool StackEmpty(Stack* ps)//检测栈是否为空,空返回真，非空返回假
{
	assert(ps);
	return ps->_top ==0;
}