#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

typedef int BTNodeType;
typedef struct BTNode
{
	BTNodeType data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

BTNode* BuyBTNode(BTNodeType x)//����ڵ�
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	node->data = x;
	node->left = node->right = NULL;
	return node;
}

void PrevOrder(BTNode* root)//ǰ�����--��->������->������
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)//�������
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)//�������
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

int BinaryTreeSize(BTNode* root)//�ڵ����
{
	if (root == NULL)
		return 0;
	else return BinaryTreeSize(root->left) 
		  + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)//Ҷ�ӽڵ����
{
	if (root == NULL)
		return 0;
	if (root->left == root->right)
		return 1;
	return BinaryTreeLeafSize(root->left)
		+ BinaryTreeLeafSize(root->right);
}

int TreeHeight(BTNode* root)//���ĸ߶�
{
	if (root == NULL)
		return 0;
	int LeftHeight = TreeHeight(root->left);
	int RightHeight = TreeHeight(root->right);
	return LeftHeight > RightHeight ? 
	       LeftHeight+1 : RightHeight+1;
}

int TreeKLevelSize(BTNode* root,int k)//��k��ڵ����,k>=1
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevelSize(root->left,k-1)
		+ TreeKLevelSize(root->right,k-1);
}

BTNode* TreeFind(BTNode* root, BTNodeType x)//����
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	struct BTNode* leftfind = TreeFind(root->left, x);
	if (leftfind != NULL)
		return leftfind;
	struct BTNode* rightfind = TreeFind(root->right, x);
	if (rightfind != NULL)
		return rightfind;
	return NULL;
}

void BinaryTreeLevelOrder(BTNode* root)// �������
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q)->data);
		QueuePop(&q);
		if (root->left != NULL)
			BinaryTreeLevelOrder(root->left);
		if (root->right != NULL)
			BinaryTreeLevelOrder(root->right);
	}
	QueueDestroy(&q);
}


bool BinaryTreeComplete(BTNode* root)// �ж϶������Ƿ�����ȫ������
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;//�����վ�ȥ�����
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	while (!QueueEmpty(&q))//����������������
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}


void BinaryTreeDestory(BTNode** proot)// ����������
{
	if (*proot == NULL)
		return;
	else
	{
		BinaryTreeDestory(&((*proot)->left));
		BinaryTreeDestory(&((*proot)->right));
		free(*proot);
		*proot = NULL;
	}
}

int main()
{
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);
	BTNode* n5 = BuyBTNode(5);
	BTNode* n6 = BuyBTNode(6);
	//�ֶ�����
	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;

	//PrevOrder(n1);
	//printf("\n");
	//InOrder(n1);
	//printf("\n");
	/*PostOrder(n1);
	printf("\n");*/
	printf("BinaryTreeSize:%d\n",BinaryTreeSize(n1));//�ڵ����
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(n1));//Ҷ�ӽڵ����
	printf("TreeHeight:%d\n", TreeHeight(n1));//���ĸ߶�
	printf("TreeKLevelSize:%d\n", TreeKLevelSize(n1,2));//���ĵ�K��ڵ����,k>=1
	printf("TreeFind:%p\n",TreeFind(n1,4));//findֵΪ4�Ľڵ�
	BinaryTreeLevelOrder(n1);//�������
	printf("\n");
	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(n1));//�ж϶������Ƿ�����ȫ������
	BinaryTreeDestory(&n1);// ����������
	return 0;
}