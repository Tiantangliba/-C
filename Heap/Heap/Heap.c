#include"Heap.h"

//void HeapCreate(Heap* hp, HPDataType* a, int n)// ���ϵ����㷨�ѵĹ���
//{
//	assert(hp);
//	HeapInit(hp);
//	for (int i = 0; i < n; i++)
//	{
//		HeapPush(hp,a[i]);
//	}
//}

void HeapCreate(Heap* hp, HPDataType* a, int n)// ���µ����㷨�ѵĹ���
{
	assert(hp);
	Heap* tmp = (Heap*)malloc(sizeof(int)*n);
	if (tmp == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	hp->_a = tmp;
	memcpy(hp->_a, a, sizeof(int)*n);
	hp->_capacity = hp->_size = n;

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(hp->_a, n, i);
	}

	//����
	int end = n - 1;
	while (end> 0)
	{
		swap(&hp->_a[0], &hp->_a[end]);
		Adjustdown(hp->_a, end, 0);
		end--;
	}
}

void HeapDestory(Heap* hp)// �ѵ�����
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

void HeapInit(Heap* hp)//�ѵĳ�ʼ��
{
	assert(hp);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp =*a;
	*a = *b;
	*b = tmp;
}

void Adjustup(HPDataType* a, int child)//���ϵ���
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])//  < ����С��
		{
			swap(&a[child],&a[parent]);
			child = parent;//�ظ�
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* hp, HPDataType x)// �ѵĲ���
{
	assert(hp);
	int newcapacity = hp->_capacity == 0 ? 4: hp->_capacity * 2;
	Heap* tmp = (Heap*)realloc(hp->_a,sizeof(HPDataType)*newcapacity);
	if (tmp == NULL)
	{
		perror("realloc failed");
		exit(-1);
	}
	hp->_a = tmp;
	hp->_a[hp->_size] = x;
	hp->_size++;
	Adjustup(hp->_a, hp->_size-1);//����˳�򣬱��ֶ�
}
void Adjustdown(HPDataType* a, int n, int parent)//���µ���
{
	int child = parent * 2 + 1;
	while (child<n)
	{
		if ((a[child+1] < a[child]) // < ����С��
		  && (child + 1<n))//��һ�����Ӵ���
			child++;     //ֻ��һ�����Ӳ��ù�
		if (a[child] < a[parent])//   < ����С��
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapPop(Heap* hp)// �ѵ�ɾ��
{
	assert(hp);
	assert(hp->_size>0);
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	Adjustdown(hp->_a, hp->_size,0);//���µ���
}

HPDataType HeapTop(Heap* hp)// ȡ�Ѷ�������
{
	assert(hp);
	assert(hp->_size > 0);
	return hp->_a[0];
}

int HeapSize(Heap* hp)// �ѵ����ݸ���
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp)// �ѵ��п�,�շ���1���ǿշ���0
{
	assert(hp);
	if (hp->_size==0)
		return 1;
	else
		return 0;
}

