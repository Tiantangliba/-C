#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>


void InsertSort(int* a, int n);// 插入排序
void ShellSort(int* a, int n);// 希尔排序
void SelectSort(int* a, int n);// 选择排序
// 堆排序
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);// 冒泡排序

void QuickSort(int* a,int begin,int end);//快排
void multiQuickSort(int* a, int begin, int end);//快排--大量重复数据时
void QuickSortNonR(int* a, int left, int right);// 快速排序 非递归实现

void MergeSort(int* a, int n);//归并排序
void MergeSortNonR(int* a, int n);//归并非递归

void CountSort(int* a, int n);//计数排序