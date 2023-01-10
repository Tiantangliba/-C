#include"Heap.h"

// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK()
{
	int n = 10000;
	int k = 5;
	//造一个数据文件
	srand((unsigned int)time(NULL));//时间戳
	FILE* creatfile = fopen("statistic.txt", "w");
	if (creatfile == NULL)
	{
		perror("creat file failed");
		exit(-1);
	}
	for (int i = n; i > 0; i--)
	{
		int val = rand();
		fprintf(creatfile, "%d\n", val);
	}
	fclose(creatfile);
	creatfile = NULL;

	// 1. 建堆--用a中前k个元素建堆
	int minHeap[5];
	FILE* outfile = fopen("statistic.txt", "r");
	if (outfile == NULL)
	{
		perror("creat file failed");
		exit(-1);
	}
	for (int i = 0; i <k; i++)
	{
		fscanf(outfile, "%d", &minHeap[i]);
	}
	
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)//找最大的数，建小堆
	{
		Adjustdown(minHeap, k, i);
	}
	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
	int val;
	while (fscanf(outfile, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
			minHeap[0] = val;
		Adjustdown(minHeap, k, 0);
	}
	for (int i = 0; i <k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	fclose(outfile);
	outfile = NULL;
}

// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(a, n, i);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

//int main()
//{
//	//PrintTopK();
//	int arr[] = { 38, 18, 27, 25, 65, 34, 19, 37, 50,40 };
//	HeapSort(arr, sizeof(arr) / sizeof(int));
//	return 0;
//}



typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BuyNode(BTDataType x)//构造节点
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	node->_data = x;
	node->_left = node->_right = NULL;
	return node;
}

void PrevOrder(BTNode* root)//前序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}
void InOrder(BTNode* root)//中序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->_left);
	printf("%d ", root->_data);
	InOrder(root->_right);
}
void PostOrder(BTNode* root)//后序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%d ", root->_data);
}
int main()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	//手动链接
	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	node4->_left = node5;
	node4->_right = node6;

	PrevOrder(node1);//前序遍历
	return 0;
}