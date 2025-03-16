#include <stdio.h>
#include <stdlib.h>

// ��������������Ľ��ṹ
typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

// ����һ���µĽ��
TreeNode *createNode(int val)
{
	TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
	if (!newNode)
	{
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// ���Ҷ����������еĽ��
TreeNode *search(TreeNode *root, int val)
{
	// �����Ϊ�ջ��ҵ�Ŀ����
	if (root == NULL || root->val == val)
	{
		return root;
	}
	// ���Ŀ��ֵС�ڸ��ڵ��ֵ���ݹ����������
	if (val < root->val)
	{
		return search(root->left, val);
	}
	// ���Ŀ��ֵ���ڸ��ڵ��ֵ���ݹ����������
	return search(root->right, val);
}

// �ڶ����������в�����
TreeNode *insert(TreeNode *root, int val)
{
	// �����Ϊ�գ������µĽ��
	if (root == NULL)
	{
		return createNode(val);
	}
	// ���Ŀ��ֵС�ڸ��ڵ��ֵ�����뵽������
	if (val < root->val)
	{
		root->left = insert(root->left, val);
	}
	// ���Ŀ��ֵ���ڸ��ڵ��ֵ�����뵽������
	else if (val > root->val)
	{
		root->right = insert(root->right, val);
	}
	// ���Ŀ��ֵ�Ѿ����������У�ʲô�����������Ը��������޸ģ�
	return root;
}

// ǰ�������ӡ����������
void preorderTraversal(TreeNode *root)
{
	if (root != NULL)
	{
		printf("%d ", root->val);		// �ȷ��ʸ��ڵ�
		preorderTraversal(root->left);	// �ٱ���������
		preorderTraversal(root->right); // ������������
	}
}

// ������
int main()
{
	TreeNode *root = NULL;
	int values[] = {20, 8, 25, 3, 10, 15, 30}; // ���в����ֵ
	int n = sizeof(values) / sizeof(values[0]);

	// �����㵽������������
	for (int i = 0; i < n; i++)
	{
		root = insert(root, values[i]);
	}

	// ��ӡǰ������������-��-�ң�
	printf("ǰ��������: ");
	preorderTraversal(root);
	printf("\n");

	// ����ĳ��ֵ�Ƿ����
	int target = 15;
	TreeNode *foundNode = search(root, target);
	if (foundNode)
	{
		printf("�ҵ��˽�㣬ֵΪ: %d\n", foundNode->val);
	}
	else
	{
		printf("δ�ҵ���� %d\n", target);
		// ���δ�ҵ�������ý��
		root = insert(root, target);
		printf("������ %d ���ǰ�����: ", target);
		preorderTraversal(root);
		printf("\n");
	}

	return 0;
}
