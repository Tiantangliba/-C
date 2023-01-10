#include"Heap.h"

//void HeapCreate(Heap* hp, HPDataType* a, int n)// 向上调整算法堆的构建
//{
//	assert(hp);
//	HeapInit(hp);
//	for (int i = 0; i < n; i++)
//	{
//		HeapPush(hp,a[i]);
//	}
//}

void HeapCreate(Heap* hp, HPDataType* a, int n)// 向下调整算法堆的构建
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

	//排序
	int end = n - 1;
	while (end> 0)
	{
		swap(&hp->_a[0], &hp->_a[end]);
		Adjustdown(hp->_a, end, 0);
		end--;
	}
}

void HeapDestory(Heap* hp)// 堆的销毁
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

void HeapInit(Heap* hp)//堆的初始化
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

void Adjustup(HPDataType* a, int child)//向上调整
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])//  < 代表小堆
		{
			swap(&a[child],&a[parent]);
			child = parent;//重复
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* hp, HPDataType x)// 堆的插入
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
	Adjustup(hp->_a, hp->_size-1);//调整顺序，保持堆
}
void Adjustdown(HPDataType* a, int n, int parent)//向下调整
{
	int child = parent * 2 + 1;
	while (child<n)
	{
		if ((a[child+1] < a[child]) // < 代表小堆
		  && (child + 1<n))//另一个孩子存在
			child++;     //只有一个孩子不用管
		if (a[child] < a[parent])//   < 代表小堆
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapPop(Heap* hp)// 堆的删除
{
	assert(hp);
	assert(hp->_size>0);
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	Adjustdown(hp->_a, hp->_size,0);//向下调整
}

HPDataType HeapTop(Heap* hp)// 取堆顶的数据
{
	assert(hp);
	assert(hp->_size > 0);
	return hp->_a[0];
}

int HeapSize(Heap* hp)// 堆的数据个数
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp)// 堆的判空,空返回1，非空返回0
{
	assert(hp);
	if (hp->_size==0)
		return 1;
	else
		return 0;
}

