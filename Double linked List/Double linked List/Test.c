#include"List.h"


void test1()
{
	ListNode*pHead= ListCreate();
	ListPushFront(pHead, 10);
	ListPushFront(pHead, 20);
	ListPushFront(pHead, 30);
	ListPushFront(pHead, 40);
	ListPopBack(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);

}

int main()
{
	test1();
	return 0;
}