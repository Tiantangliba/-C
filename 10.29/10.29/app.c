

#include"Seqlist.h"

TestSeqList1()
{
	SeqList s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1,1);
	SeqListPrint(&s1);
	SeqListPopBack(&s1);
	SeqListPrint(&s1); 
	//SeqListPopBack(&s1);
	SeqListDestroy(&s1);
}

//int main()
//{
//	TestSeqList1();
//	return 0;
//}