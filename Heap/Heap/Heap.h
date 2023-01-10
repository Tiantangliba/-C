#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<time.h>


typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;


void HeapCreate(Heap* hp, HPDataType* a, int n);// �ѵĹ���
void HeapInit(Heap* hp);//�ѵĳ�ʼ��
void HeapDestory(Heap* hp);// �ѵ�����
void Adjustup(HPDataType* a, int child);//���ϵ���
void HeapPush(Heap* hp, HPDataType x);// �ѵĲ���
void Adjustdown(HPDataType* a, int n, int parent);//���µ���
void HeapPop(Heap* hp);// �ѵ�ɾ��
HPDataType HeapTop(Heap* hp);// ȡ�Ѷ�������

int HeapSize(Heap* hp);// �ѵ����ݸ���

int HeapEmpty(Heap* hp);// �ѵ��п�,�շ���1���ǿշ���0

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK();
void TestTopk();