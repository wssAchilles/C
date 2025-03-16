#include <stdio.h>
#include <stdlib.h>

// 定义二叉排序树的结点结构
typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

// 创建一个新的结点
TreeNode *createNode(int val)
{
	TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
	if (!newNode)
	{
		printf("内存分配失败\n");
		return NULL;
	}
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// 查找二叉排序树中的结点
TreeNode *search(TreeNode *root, int val)
{
	// 如果树为空或找到目标结点
	if (root == NULL || root->val == val)
	{
		return root;
	}
	// 如果目标值小于根节点的值，递归查找左子树
	if (val < root->val)
	{
		return search(root->left, val);
	}
	// 如果目标值大于根节点的值，递归查找右子树
	return search(root->right, val);
}

// 在二叉排序树中插入结点
TreeNode *insert(TreeNode *root, int val)
{
	// 如果树为空，创建新的结点
	if (root == NULL)
	{
		return createNode(val);
	}
	// 如果目标值小于根节点的值，插入到左子树
	if (val < root->val)
	{
		root->left = insert(root->left, val);
	}
	// 如果目标值大于根节点的值，插入到右子树
	else if (val > root->val)
	{
		root->right = insert(root->right, val);
	}
	// 如果目标值已经存在于树中，什么都不做（可以根据需求修改）
	return root;
}

// 前序遍历打印二叉排序树
void preorderTraversal(TreeNode *root)
{
	if (root != NULL)
	{
		printf("%d ", root->val);		// 先访问根节点
		preorderTraversal(root->left);	// 再遍历左子树
		preorderTraversal(root->right); // 最后遍历右子树
	}
}

// 主函数
int main()
{
	TreeNode *root = NULL;
	int values[] = {20, 8, 25, 3, 10, 15, 30}; // 树中插入的值
	int n = sizeof(values) / sizeof(values[0]);

	// 插入结点到二叉排序树中
	for (int i = 0; i < n; i++)
	{
		root = insert(root, values[i]);
	}

	// 打印前序遍历结果（根-左-右）
	printf("前序遍历结果: ");
	preorderTraversal(root);
	printf("\n");

	// 查找某个值是否存在
	int target = 15;
	TreeNode *foundNode = search(root, target);
	if (foundNode)
	{
		printf("找到了结点，值为: %d\n", foundNode->val);
	}
	else
	{
		printf("未找到结点 %d\n", target);
		// 如果未找到，插入该结点
		root = insert(root, target);
		printf("插入结点 %d 后的前序遍历: ", target);
		preorderTraversal(root);
		printf("\n");
	}

	return 0;
}
