#include"Sort.h"
#include"Stack.h"



int main()
{
	//int arr[] = { 5, 4, 6, 9, 8, 2, 1, 0 ,5,11,7};
	int arr[] = { 5, 5, 5, 9, 8, 2, 5, 0, 5, 15, 7 };

	int n = sizeof(arr) / sizeof(int);

	//InsertSort(arr, n);// ��������
	//ShellSort(arr, n);// ϣ������
	//SelectSort(arr, n);// ѡ������
	//HeapSort(arr, n);//����
	//BubbleSort(arr, n);// ð������
	//QuickSort(arr, 0 ,n-1);//����
	multiQuickSort(arr,0, n-1);//����--�����ظ�����ʱ
	//QuickSortNonR(arr, 0, n - 1);// �������� �ǵݹ�ʵ��
	//MergeSort(arr, n);//�鲢
	//CountSort(arr, n);//��������
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}