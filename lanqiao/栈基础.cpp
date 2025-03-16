#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000 // 定义最大字符序列长度

// 定义栈结构
struct Stack{
    char data[MAX_SIZE];
    int top;
};

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

// 读取栈顶元素（不弹出）
char peek(Stack *s) {
    if (!isStackEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

// 主函数：判断回文
int main() {
    Stack stack;
    char input[MAX_SIZE];
    int length = 0;

    // 初始化栈
    initStack(&stack);

    printf("请输入以@结束的字符序列：\n");
    scanf("%s", input);

    // 找到序列长度，排除'@'
    for (length = 0; input[length] != '@'; length++) {
        push(&stack, input[length]); // 所有字符入栈
    }

    // 判断回文
    for (int i = 0; i < length / 2; i++) {
        char topChar = pop(&stack); // 栈顶字符
        if (topChar != input[i]) { // 比较栈顶和原始输入前半部分
            printf("该字符序列不是回文。\n");
            return 0;
        }
    }

    printf("该字符序列是回文。\n");
    return 0;
}
