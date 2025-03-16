#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int find_max(Node* head) {
    if (head == NULL) return -1;  // 链表为空
    
    int max_value = head->data;
    Node* current = head->next;
    
    while (current != NULL) {
        if (current->data > max_value) {
            max_value = current->data;
        }
        current = current->next;
    }
    return max_value;
}

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    // 构造链表
    Node* head = newNode(1);
    head->next = newNode(7);
    head->next->next = newNode(3);
    
    int max_value = find_max(head);
    
    printf("链表中最大值为: %d\n", max_value);
    
    return 0;
}
