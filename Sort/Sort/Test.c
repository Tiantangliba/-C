#include"Sort.h"
#include"Stack.h"



int main()
{
	//int arr[] = { 5, 4, 6, 9, 8, 2, 1, 0 ,5,11,7};
	int arr[] = { 5, 5, 5, 9, 8, 2, 5, 0, 5, 15, 7 };

	int n = sizeof(arr) / sizeof(int);

	//InsertSort(arr, n);// 插入排序
	//ShellSort(arr, n);// 希尔排序
	//SelectSort(arr, n);// 选择排序
	//HeapSort(arr, n);//堆排
	//BubbleSort(arr, n);// 冒泡排序
	//QuickSort(arr, 0 ,n-1);//快排
	multiQuickSort(arr,0, n-1);//快排--大量重复数据时
	//QuickSortNonR(arr, 0, n - 1);// 快速排序 非递归实现
	//MergeSort(arr, n);//归并
	//CountSort(arr, n);//计数排序
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}