// 二叉树先序递归非递归遍历
#include <stdio.h>
#include <stdlib.h>
#include <stack>
// 定义二叉树节点结构
struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};
// 创建一个新节点
TreeNode *createNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1); // 如果内存分配失败，程序终止
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// 递归先序遍历
void preOrderRecursive(TreeNode *root)
{
    if (root == NULL)
        return;                     // 递归终止条件：空节点
    printf("%d ", root->value);     // 访问根节点
    preOrderRecursive(root->left);  // 遍历左子树
    preOrderRecursive(root->right); // 遍历右子树
}

// 非递归先序遍历
void preOrderIterative(TreeNode *root)
{
    if (root == NULL)
        return;

    // 创建一个栈来模拟递归过程
    std::stack<TreeNode *> stack;
    stack.push(root);

    while (!stack.empty())
    {
        TreeNode *node = stack.top();
        stack.pop();
        printf("%d ", node->value); // 访问节点
        // 先将右子树压入栈中，因为栈是LIFO，所以先右后左
        if (node->right)
        {
            stack.push(node->right);
        }
        // 再将左子树压入栈中
        if (node->left)
        {
            stack.push(node->left);
        }
    }
}
int main()
{
    // 创建一个简单的二叉树
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->left->left=createNode(6);
    root->left->left->right=createNode(7);
    root->left->right = createNode(5);
    root->right->right = createNode(8);
    root->right->right->left=createNode(9);
    root->right->right->right=createNode(10);
    // 递归先序遍历
    printf("Recursive Pre-order Traversal: ");
    preOrderRecursive(root);
    printf("\n");

    // 非递归先序遍历
    printf("Iterative Pre-order Traversal: ");
    preOrderIterative(root);
    printf("\n");

    return 0;
}
