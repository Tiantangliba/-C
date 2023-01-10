#include"Stack.h"

void StackInit(Stack* ps)//��ʼ��ջ
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)//��ջ
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

void StackDestroy(Stack* ps)//����ջ
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackPop(Stack* ps)//��ջ
{
	assert(ps);
	assert(ps->_top > 0);
	ps->_top--;
}

STDataType StackTop(Stack* ps)//��ȡջ��Ԫ��
{
	assert(ps);
	assert(ps->_top > 0);
	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)//��ȡջ��Ԫ�صĸ���
{
	assert(ps);
	return ps->_top;
}

bool StackEmpty(Stack* ps)//���ջ�Ƿ�Ϊ��,�շ����棬�ǿշ��ؼ�
{
	assert(ps);
	return ps->_top ==0;
}