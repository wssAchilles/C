#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // ��������ַ����г���

// ����ջ�ṹ
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// ��ʼ��ջ
void initStack(Stack *s) {
    s->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int isStackEmpty(Stack *s) {
    return s->top == -1;
}

// ��ջ����
void push(Stack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = c;
    }
}

// ��ջ����
char pop(Stack *s) {
    if (!isStackEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0'; // ��ջ���ؿ��ַ�
}

// ������нṹ
typedef struct {
    char data[MAX_SIZE];
    int front, rear;
} Queue;

// ��ʼ������
void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

// ��Ӳ���
void enqueue(Queue *q, char c) {
    if ((q->rear + 1) % MAX_SIZE != q->front) { // ����δ��
        q->data[q->rear] = c;
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
}

// ���Ӳ���
char dequeue(Queue *q) {
    if (!isQueueEmpty(q)) {
        char c = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        return c;
    }
    return '\0'; // �ն��з��ؿ��ַ�
}

// ���������б����
int main() {
    Stack stack;
    Queue queue;
    char input[MAX_SIZE];
    char c;
    
    // ��ʼ��ջ�Ͷ���
    initStack(&stack);
    initQueue(&queue);

    printf("��������@�������ַ����У�\n");
    scanf("%s", input);

    // �������룬����@
    for (int i = 0; input[i] != '@'; i++) {
        c = input[i];
        push(&stack, c);    // ��ջ
        enqueue(&queue, c); // ���
    }

    // �Ƚ�ջ�Ͷ����е��ַ�
    while (!isStackEmpty(&stack) && !isQueueEmpty(&queue)) {
        if (pop(&stack) != dequeue(&queue)) {
            printf("���ַ����в��ǻ��ġ�\n");
            return 0;
        }
    }

    printf("���ַ������ǻ��ġ�\n");
    return 0;
}
