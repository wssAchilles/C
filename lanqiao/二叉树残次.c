#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *left;
	struct node *right;
}BiNode,*BiTree;
//���򴴽�������
void CreatBtee(BiTree *bt)
{
	char data;
	scanf("%c",&data);
	if(data=='.')
	{
		*bt=NULL;
	}else{
		//�����ڴ�ռ�
		*bt=(BiTree)malloc(sizeof(BiNode));
		(*bt)->data=data;
		CreatBtee(&((*bt)->left));
		CreatBtee(&((*bt)->right));
	}
}
//�������Ĵ洢
//˳��洢-����
//��ʽ�洢-����
void PreOeder(BiNode *bt)//�������
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