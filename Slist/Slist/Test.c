#include"SList.h"

void Test1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFront(&plist, 10);
	SListPrint(plist);
}


int main()
{
	Test1();
	return 0;
}
