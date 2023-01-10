#include"Stack.h"
#include"Queue.h"

Test1()
{
	Queue ps;
	StackInit(&ps);
	QueuePush(&ps, 5);
}

int main()
{
	Test1();
	return 0;
}

