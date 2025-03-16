#include <stdio.h>
#include <stdlib.h>
#include <stack>
// ����������ڵ�ṹ
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
// ����һ���µ����ڵ�
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        return NULL;
    }
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// ǰ��������ݹ飩
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);  // ���ʸ��ڵ�
    preorderTraversal(root->left);  // ����������
    preorderTraversal(root->right);  // ����������
}

// ����������ݹ飩
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);  // ����������
    printf("%d ", root->val);  // ���ʸ��ڵ�
    inorderTraversal(root->right);  // ����������
}

// ����������ݹ飩
void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);  // ����������
    postorderTraversal(root->right);  // ����������
    printf("%d ", root->val);  // ���ʸ��ڵ�
}


// ǰ��������ǵݹ飩
void preorderTraversalIterative(TreeNode* root) {
    if (root == NULL) return;
    
    std::stack<TreeNode*> stack;
    stack.push(root);
    
    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        printf("%d ", node->val);
        
        // �Ƚ�������ѹջ���ٽ�������ѹջ����Ϊջ�Ǻ���ȳ��������������ȴ���
        if (node->right) stack.push(node->right);
        if (node->left) stack.push(node->left);
    }
}

// ����������ǵݹ飩
void inorderTraversalIterative(TreeNode* root) {
    std::stack<TreeNode*> stack;
    TreeNode* current = root;
    
    while (current != NULL || !stack.empty()) {
        // �����������
        while (current != NULL) {
            stack.push(current);
            current = current->left;
        }
        
        // ����ջ��Ԫ��
        current = stack.top();
        stack.pop();
        printf("%d ", current->val);
        
        // ����������
        current = current->right;
    }
}

// ����������ǵݹ飩
void postorderTraversalIterative(TreeNode* root) {
    if (root == NULL) return;
    
    std::stack<TreeNode*> stack1, stack2;
    stack1.push(root);
    
    while (!stack1.empty()) {
        TreeNode* node = stack1.top();
        stack1.pop();
        stack2.push(node);
        
        // �Ƚ�������ѹջ���ٽ�������ѹջ
        if (node->left) stack1.push(node->left);
        if (node->right) stack1.push(node->right);
    }
    
    // �������ջ2�е�Ԫ��
    while (!stack2.empty()) {
        printf("%d ", stack2.top()->val);
        stack2.pop();
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
    preorderTraversal(root);
    printf("\n");

    // �ǵݹ��������
    printf("Iterative Pre-order Traversal: ");
    preorderTraversalIterative(root);
    printf("\n");

    return 0;
}

