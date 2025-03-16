#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // 定义最大字符序列长度

// 定义栈结构
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int isStackEmpty(Stack *s) {
    return s->top == -1;
}

// 入栈操作
void push(Stack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = c;
    }
}

// 出栈操作
char pop(Stack *s) {
    if (!isStackEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0'; // 空栈返回空字符
}

// 定义队列结构
typedef struct {
    char data[MAX_SIZE];
    int front, rear;
} Queue;

// 初始化队列
void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

// 判断队列是否为空
int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

// 入队操作
void enqueue(Queue *q, char c) {
    if ((q->rear + 1) % MAX_SIZE != q->front) { // 队列未满
        q->data[q->rear] = c;
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
}

// 出队操作
char dequeue(Queue *q) {
    if (!isQueueEmpty(q)) {
        char c = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        return c;
    }
    return '\0'; // 空队列返回空字符
}

// 主函数，判别回文
int main() {
    Stack stack;
    Queue queue;
    char input[MAX_SIZE];
    char c;
    
    // 初始化栈和队列
    initStack(&stack);
    initQueue(&queue);

    printf("请输入以@结束的字符序列：\n");
    scanf("%s", input);

    // 遍历输入，忽略@
    for (int i = 0; input[i] != '@'; i++) {
        c = input[i];
        push(&stack, c);    // 入栈
        enqueue(&queue, c); // 入队
    }

    // 比较栈和队列中的字符
    while (!isStackEmpty(&stack) && !isQueueEmpty(&queue)) {
        if (pop(&stack) != dequeue(&queue)) {
            printf("该字符序列不是回文。\n");
            return 0;
        }
    }

    printf("该字符序列是回文。\n");
    return 0;
}
