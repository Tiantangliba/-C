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

BTNode* BuyBTNode(BTNodeType x)//构造节点
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

void PrevOrder(BTNode* root)//前序遍历--根->左子树->右子树
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

void InOrder(BTNode* root)//中序遍历
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

void PostOrder(BTNode* root)//后序遍历
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

int BinaryTreeSize(BTNode* root)//节点个数
{
	if (root == NULL)
		return 0;
	else return BinaryTreeSize(root->left) 
		  + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)//叶子节点个数
{
	if (root == NULL)
		return 0;
	if (root->left == root->right)
		return 1;
	return BinaryTreeLeafSize(root->left)
		+ BinaryTreeLeafSize(root->right);
}

int TreeHeight(BTNode* root)//树的高度
{
	if (root == NULL)
		return 0;
	int LeftHeight = TreeHeight(root->left);
	int RightHeight = TreeHeight(root->right);
	return LeftHeight > RightHeight ? 
	       LeftHeight+1 : RightHeight+1;
}

int TreeKLevelSize(BTNode* root,int k)//第k层节点个数,k>=1
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevelSize(root->left,k-1)
		+ TreeKLevelSize(root->right,k-1);
}

BTNode* TreeFind(BTNode* root, BTNodeType x)//查找
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

void BinaryTreeLevelOrder(BTNode* root)// 层序遍历
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


bool BinaryTreeComplete(BTNode* root)// 判断二叉树是否是完全二叉树
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
			break;//出到空就去检查了
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	while (!QueueEmpty(&q))//遇到空来检查后面了
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


void BinaryTreeDestory(BTNode** proot)// 二叉树销毁
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
	//手动链接
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
	printf("BinaryTreeSize:%d\n",BinaryTreeSize(n1));//节点个数
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(n1));//叶子节点个数
	printf("TreeHeight:%d\n", TreeHeight(n1));//树的高度
	printf("TreeKLevelSize:%d\n", TreeKLevelSize(n1,2));//树的第K层节点个数,k>=1
	printf("TreeFind:%p\n",TreeFind(n1,4));//find值为4的节点
	BinaryTreeLevelOrder(n1);//层序遍历
	printf("\n");
	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(n1));//判断二叉树是否是完全二叉树
	BinaryTreeDestory(&n1);// 二叉树销毁
	return 0;
}