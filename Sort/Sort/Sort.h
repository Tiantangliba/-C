#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>


void InsertSort(int* a, int n);// ��������
void ShellSort(int* a, int n);// ϣ������
void SelectSort(int* a, int n);// ѡ������
// ������
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);// ð������

void QuickSort(int* a,int begin,int end);//����
void multiQuickSort(int* a, int begin, int end);//����--�����ظ�����ʱ
void QuickSortNonR(int* a, int left, int right);// �������� �ǵݹ�ʵ��

void MergeSort(int* a, int n);//�鲢����
void MergeSortNonR(int* a, int n);//�鲢�ǵݹ�

void CountSort(int* a, int n);//��������