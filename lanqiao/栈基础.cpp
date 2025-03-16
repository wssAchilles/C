#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000 // ��������ַ����г���

// ����ջ�ṹ
struct Stack{
    char data[MAX_SIZE];
    int top;
};

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

// ��ȡջ��Ԫ�أ���������
char peek(Stack *s) {
    if (!isStackEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

// ���������жϻ���
int main() {
    Stack stack;
    char input[MAX_SIZE];
    int length = 0;

    // ��ʼ��ջ
    initStack(&stack);

    printf("��������@�������ַ����У�\n");
    scanf("%s", input);

    // �ҵ����г��ȣ��ų�'@'
    for (length = 0; input[length] != '@'; length++) {
        push(&stack, input[length]); // �����ַ���ջ
    }

    // �жϻ���
    for (int i = 0; i < length / 2; i++) {
        char topChar = pop(&stack); // ջ���ַ�
        if (topChar != input[i]) { // �Ƚ�ջ����ԭʼ����ǰ�벿��
            printf("���ַ����в��ǻ��ġ�\n");
            return 0;
        }
    }

    printf("���ַ������ǻ��ġ�\n");
    return 0;
}
