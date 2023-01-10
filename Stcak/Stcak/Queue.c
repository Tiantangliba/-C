#include"Queue.h"
 
void QueueInit(Queue* q)// 初始化队列
{
	assert(q);
	q->_front = q->_rear = NULL;
	q->size = 0;
}


void QueueDestroy(Queue* q)// 销毁队列 
{
	assert(q);
	QNode* cur = q->_front;
	while (cur)
	{
		q->_front = cur->_next;
		free(cur);
		cur = q->_front;
	}
	q->_front = q->_rear = NULL;
	q->size = 0;
}


void QueuePush(Queue* q, QDataType data)// 队尾入队列 
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->_data = data;
	newnode->_next = NULL;
	if (q->_front == NULL)//无节点情况
	{
		q->_front = q->_rear = newnode;
		q->size++;
	}
	else//有节点的情况
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
		q->size++;
	}
}


void QueuePop(Queue* q)// 队头出队列 
{
	assert(q);
	//assert(q->_front);//无节点情况
	assert(!QueueEmpty(q));
	if (q->_front->_next == NULL;)//只有一个节点的情况
	{
		free(q->_front);
		q->_rear = q->_front = NULL;
		q->size--;
	}
	else//其他的情况
	{
		QNode* cur = q->_front;
		q->_front = q->_front->_next;
		free(cur);
		q->size--;
	}
}


QDataType QueueFront(Queue* q)// 获取队列头部元素 
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_front->_data;
}


QDataType QueueBack(Queue* q)// 获取队列队尾元素 
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_rear->_data;
}


bool QueueEmpty(Queue* q)// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
{
	assert(q);
	return q->_rear == NULL && q->_rear == NULL;
}

 
int QueueSize(Queue* q)// 获取队列中有效元素个数
{
	assert(q);
	return q->size;
}