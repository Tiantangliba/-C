#include"Seqlist.h"
void SeqListInit(SeqList* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListCheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		SLDateType* tmp = (SLDateType*)realloc(ps->a, newcapacity*sizeof(SeqList));
		if (tmp == NULL)
		{
			printf("À©ÈÝÊ§°Ü\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}


void SeqListPushBack(SeqList* ps, SLDateType x)//Î²²å
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}


void SeqListDestroy(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


void SeqListPrint(SeqList* ps)
{
	size_t i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


void SeqListPopBack(SeqList* ps)//Î²É¾
{
	assert(ps->size > 0);
	ps->size--;
}
void SeqListPushFront(SeqList* ps, SLDateType x)//Í·²å
{
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}


void SeqListPopFront(SeqList* ps)//Í·É¾
{
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
}


int SeqListFind(SeqList* ps, SLDateType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}


void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	SeqListCheckCapacity(ps);
	assert(pos >= 0 && pos <= ps->size);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}


void SeqListErase(SeqList* ps, size_t pos)
{
	assert(pos >= 0 && pos <= ps->size);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}