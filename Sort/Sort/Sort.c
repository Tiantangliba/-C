#include"Sort.h"//升序
#include"Stack.h"

void InsertSort(int* a, int n)// 插入排序
{
	for (int i = 0; i<n-1; i++)
	{
		int end=i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp > a[end])
			{
				break;
			}
			else
			{
				a[end + 1] = a[end];
				end--;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)// 希尔排序
{
	//int gap=n;
	//while (gap > 1)
	//{
	//	//gap = gap / 2;
	//	gap = gap/3 +1;
	//	for (int j = 0; j < gap; j++)
	//	{
	//		for (int i = j; i<n - gap; i += gap)
	//		{
	//			int end = i;
	//			int tmp = a[end + gap];
	//			while (end >= 0)
	//			{
	//				if (tmp > a[end])
	//					break;
	//				else
	//				{
	//					a[end + gap] = a[end];
	//					end -= gap;
	//				}
	//			}
	//			a[end + gap] = tmp;
	//		}
	//	} 
	//}

	int gap = n;
	while (gap > 1)
	{
		//gap = gap / 2;
		gap = gap / 3 + 1;
		for (int i = 0; i<n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp > a[end])
					break;
				else
				{
					a[end + gap] = a[end];
					end -= gap;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* a,int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void SelectSort(int* a, int n)// 选择排序
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
				mini = i;
			if (a[i]>a[maxi])
				maxi = i;
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;
		Swap(&a[end], &a[maxi]);
		begin++; 
		end--;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child<n)
	{
		if ((a[child + 1] > a[child]) // > 代表小堆
			&& (child + 1<n))//另一个孩子存在
			child++;     //只有一个孩子不用管
		if (a[child] > a[parent])//   > 代表小堆
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n)
{
	//升序建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//排序
	int end = n - 1;
	while (end> 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void BubbleSort(int* a, int n)// 冒泡排序
{
	for (int j = 0; j < n; j++)
	{
		int check = 1;
		for (int i = 0; i < n - 1-j; i++)
		{
			if (a[i]>a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				check = 0;
			}
		}
		if (check == 1)
			break;
	}
}

int PartSort1(int* a, int begin, int end)//Hoare版本
{
	//第一层优化:三数取中间大小的，交换到边上做key，
	//解决最坏的O(N*N)的情况
	//实现略

	//第二层优化：小区间优化
	//二叉树的角度：最下面一层的递归次数太多（占一半）
	//分割到小区间时，用直接插入排序
	//实现略
	int left = begin;
	int right = end;
	int key = left;
	while (left < right)
	{
		//左值为key，右边先走
		while (left < right&& a[right] >= a[key])
		{
			right--;
		}
		while (left < right&& a[left] <= a[key])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[key]);
	key = left;
	return key;
}

int PartSort2(int* a, int begin, int end)//挖坑法
{
	int left =begin;
	int right = end;
	int tmp = a[left];
	int hole = left;
	while (left<right)
	{
		while (left < right&&a[right] >= tmp)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right&&a[left] <= tmp)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = tmp;
	return hole;
}

int PartSort3(int* a, int begin, int end)//双指针法
{
	int cur = begin + 1;
	int prev = begin;
	int key = begin;
	while (cur <= end)
	{
		if (a[cur] < a[key])
		{
			Swap(&a[++prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[key]);
	return prev;
}
void QuickSort(int* a,int begin,int end)//快排
{
	if (begin >= end)//递归结束条件
	{
		return;
	}

	//int key = PartSort1(a, begin, end);
    //int key = PartSort2(a, begin, end);
	int key = PartSort3(a, begin, end);

	//递归
	QuickSort(a, begin, key-1);
	QuickSort(a, key + 1, end);
}

void QuickSortNonR(int* a, int begin, int end)// 快速排序 非递归实现
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);
		int key = PartSort1(a, left, right);
		
		if (key + 1 < right)
		{
			StackPush(&st, key + 1);
			StackPush(&st, right);
		}

		if (left < key - 1)
		{
			StackPush(&st, left);
			StackPush(&st, key - 1);
		}
	}
	StackDestroy(&st);
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}

	int mid = (begin + end) / 2;
	//[begin,mid][mid+1,end]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);

	//归并
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int i = begin;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}

//时间复杂度O(N*logN) 空间复杂度O(N+logN)
//消耗了malloc空间+递归调用空间(看的深度，因为会利用用过的空间)
void MergeSort(int* a, int n)//归并排序  
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int n)//归并非递归
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	int rangeN = 1;
	while (rangeN < n)
	{
		for (int i = 0; i < n; i += 2 * rangeN)
		{
			int begin1 = i;
			int end1 = i + rangeN - 1;
			int begin2 = i + rangeN;
			int end2 = i + rangeN * 2;
			int j = i;

			if (end1 >= n)
			{
				//修正区间
				//end1 = n - 1;
				//begin2 = n;
				//end2 = n - 1;
				
				break;
			}
			else if (begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1&&begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int)*(end2 - i + 1));
		}
		rangeN *= 2;
	}
	
	free(tmp);
	tmp = NULL;
}