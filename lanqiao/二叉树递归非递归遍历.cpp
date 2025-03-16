#include <stdio.h>
#include <stdlib.h>
#include <stack>
// 定义二叉树节点结构
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
// 创建一个新的树节点
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// 前序遍历（递归）
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);  // 访问根节点
    preorderTraversal(root->left);  // 遍历左子树
    preorderTraversal(root->right);  // 遍历右子树
}

// 中序遍历（递归）
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);  // 遍历左子树
    printf("%d ", root->val);  // 访问根节点
    inorderTraversal(root->right);  // 遍历右子树
}

// 后序遍历（递归）
void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);  // 遍历左子树
    postorderTraversal(root->right);  // 遍历右子树
    printf("%d ", root->val);  // 访问根节点
}


// 前序遍历（非递归）
void preorderTraversalIterative(TreeNode* root) {
    if (root == NULL) return;
    
    std::stack<TreeNode*> stack;
    stack.push(root);
    
    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        printf("%d ", node->val);
        
        // 先将右子树压栈，再将左子树压栈，因为栈是后进先出，所以左子树先处理
        if (node->right) stack.push(node->right);
        if (node->left) stack.push(node->left);
    }
}

// 中序遍历（非递归）
void inorderTraversalIterative(TreeNode* root) {
    std::stack<TreeNode*> stack;
    TreeNode* current = root;
    
    while (current != NULL || !stack.empty()) {
        // 遍历到最左边
        while (current != NULL) {
            stack.push(current);
            current = current->left;
        }
        
        // 处理栈顶元素
        current = stack.top();
        stack.pop();
        printf("%d ", current->val);
        
        // 遍历右子树
        current = current->right;
    }
}

// 后序遍历（非递归）
void postorderTraversalIterative(TreeNode* root) {
    if (root == NULL) return;
    
    std::stack<TreeNode*> stack1, stack2;
    stack1.push(root);
    
    while (!stack1.empty()) {
        TreeNode* node = stack1.top();
        stack1.pop();
        stack2.push(node);
        
        // 先将左子树压栈，再将右子树压栈
        if (node->left) stack1.push(node->left);
        if (node->right) stack1.push(node->right);
    }
    
    // 反向输出栈2中的元素
    while (!stack2.empty()) {
        printf("%d ", stack2.top()->val);
        stack2.pop();
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
    preorderTraversal(root);
    printf("\n");

    // 非递归先序遍历
    printf("Iterative Pre-order Traversal: ");
    preorderTraversalIterative(root);
    printf("\n");

    return 0;
}

