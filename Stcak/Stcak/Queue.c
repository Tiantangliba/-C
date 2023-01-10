#include"Queue.h"
 
void QueueInit(Queue* q)// ��ʼ������
{
	assert(q);
	q->_front = q->_rear = NULL;
	q->size = 0;
}


void QueueDestroy(Queue* q)// ���ٶ��� 
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


void QueuePush(Queue* q, QDataType data)// ��β����� 
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
	if (q->_front == NULL)//�޽ڵ����
	{
		q->_front = q->_rear = newnode;
		q->size++;
	}
	else//�нڵ�����
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
		q->size++;
	}
}


void QueuePop(Queue* q)// ��ͷ������ 
{
	assert(q);
	//assert(q->_front);//�޽ڵ����
	assert(!QueueEmpty(q));
	if (q->_front->_next == NULL;)//ֻ��һ���ڵ�����
	{
		free(q->_front);
		q->_rear = q->_front = NULL;
		q->size--;
	}
	else//���������
	{
		QNode* cur = q->_front;
		q->_front = q->_front->_next;
		free(cur);
		q->size--;
	}
}


QDataType QueueFront(Queue* q)// ��ȡ����ͷ��Ԫ�� 
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_front->_data;
}


QDataType QueueBack(Queue* q)// ��ȡ���ж�βԪ�� 
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_rear->_data;
}


bool QueueEmpty(Queue* q)// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
{
	assert(q);
	return q->_rear == NULL && q->_rear == NULL;
}

 
int QueueSize(Queue* q)// ��ȡ��������ЧԪ�ظ���
{
	assert(q);
	return q->size;
}