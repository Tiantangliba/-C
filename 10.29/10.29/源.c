 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void merge(int* nums1, int m, int* nums2,  int n)
{
	int* num = nums1;
	int dst = 0;
	int src1 = 0;
	int src2 = 0;
	while ((src1<m) && (src2<n))
	{
		if (nums1[src1]<nums2[src2])
		{
			num[dst++] = nums1[src1++];
		}
		else
		{
			num[dst++] = nums2[src2++];
		}
	}
	if (src1 == m)
	{
		while (src2<n)
		{
			num[dst++] = nums2[src2++];
		}
	}
	else
	{
		while (src1<n)
		{
			num[dst++] = nums1[src1++];
		}
	}
	for (dst = 0; dst<m + n; dst++)
	{
		nums1[dst] = num[dst];
	}
}

int main()
{
	int nums1[] = { 1, 2, 3, 0, 0, 0 };
	int nums2[] = { 2, 5, 6 };
	int m = 3;
	int n = 3;
	merge(nums1, m, nums2, n);
	for (int i = 0; i < 6; i++)
	{
		printf("%d  ", nums1[i]);
	}
	return 0;
}