#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>


void InsertSort(int* a, int n);// ≤Â»Î≈≈–Ú
void ShellSort(int* a, int n);// œ£∂˚≈≈–Ú
void SelectSort(int* a, int n);// —°‘Ò≈≈–Ú
// ∂—≈≈–Ú
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);// √∞≈›≈≈–Ú
void QuickSort(int* a,int begin,int end);//øÏ≈≈
void QuickSortNonR(int* a, int left, int right);// øÏÀŸ≈≈–Ú ∑«µ›πÈ µœ÷
void MergeSort(int* a, int n);//πÈ≤¢≈≈–Ú
void MergeSortNonR(int* a, int n);//πÈ≤¢∑«µ›πÈ