#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *left;
	struct node *right;
}BiNode,*BiTree;
//先序创建二叉树
void CreatBtee(BiTree *bt)
{
	char data;
	scanf("%c",&data);
	if(data=='.')
	{
		*bt=NULL;
	}else{
		//申请内存空间
		*bt=(BiTree)malloc(sizeof(BiNode));
		(*bt)->data=data;
		CreatBtee(&((*bt)->left));
		CreatBtee(&((*bt)->right));
	}
}
//二叉树的存储
//顺序存储-数组
//链式存储-链表
void PreOeder(BiNode *bt)//先序遍历
{
	if(bt!=NULL)
	{
		printf("%c",bt->data);
		PreOeder(bt->left);
		PreOeder(bt->right);
	}
}
int main()
{
	BiTree bt;
	CreatBtee(&bt);
}