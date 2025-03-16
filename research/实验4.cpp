// ����������ݹ�ǵݹ����
#include <stdio.h>
#include <stdlib.h>
#include <stack>
// ����������ڵ�ṹ
struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};
// ����һ���½ڵ�
TreeNode *createNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1); // ����ڴ����ʧ�ܣ�������ֹ
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// �ݹ��������
void preOrderRecursive(TreeNode *root)
{
    if (root == NULL)
        return;                     // �ݹ���ֹ�������սڵ�
    printf("%d ", root->value);     // ���ʸ��ڵ�
    preOrderRecursive(root->left);  // ����������
    preOrderRecursive(root->right); // ����������
}

// �ǵݹ��������
void preOrderIterative(TreeNode *root)
{
    if (root == NULL)
        return;

    // ����һ��ջ��ģ��ݹ����
    std::stack<TreeNode *> stack;
    stack.push(root);

    while (!stack.empty())
    {
        TreeNode *node = stack.top();
        stack.pop();
        printf("%d ", node->value); // ���ʽڵ�
        // �Ƚ�������ѹ��ջ�У���Ϊջ��LIFO���������Һ���
        if (node->right)
        {
            stack.push(node->right);
        }
        // �ٽ�������ѹ��ջ��
        if (node->left)
        {
            stack.push(node->left);
        }
    }
}
int main()
{
    // ����һ���򵥵Ķ�����
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
    // �ݹ��������
    printf("Recursive Pre-order Traversal: ");
    preOrderRecursive(root);
    printf("\n");

    // �ǵݹ��������
    printf("Iterative Pre-order Traversal: ");
    preOrderIterative(root);
    printf("\n");

    return 0;
}
