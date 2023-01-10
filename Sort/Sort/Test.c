#include"Sort.h"
#include"Stack.h"



int main()
{
	int arr[] = { 5, 4, 6, 9, 8, 2, 1, 0 ,5,11,7};
	int n = sizeof(arr) / sizeof(int);

	//InsertSort(arr, n);// ≤Â»Î≈≈–Ú
	//ShellSort(arr, n);// œ£∂˚≈≈–Ú
	//SelectSort(arr, n);// —°‘Ò≈≈–Ú
	//HeapSort(arr, n);//∂—≈≈
	//BubbleSort(arr, n);// √∞≈›≈≈–Ú
	//QuickSort(arr, 0 ,n-1);//øÏ≈≈
	//QuickSortNonR(arr, 0, n - 1);// øÏÀŸ≈≈–Ú ∑«µ›πÈ µœ÷
	MergeSort(arr, n);//πÈ≤¢
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}