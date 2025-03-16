#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100

// 图书信息结构体
typedef struct Book {
    char isbn[20];        // ISBN
    char title[MAX_TITLE_LENGTH]; // 书名
    float price;          // 价格
    struct Book* next;    // 链表的下一个节点
}Book;

// 创建一个新的图书节点
Book* createBook(char* isbn,char* title, float price) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->isbn, isbn);
    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->next = NULL;
    return newBook;
}

// 查找图书，返回图书的位置（从0开始的索引）
int findBook(Book* head,char* isbn,char* title) {
    Book* current = head;
    int index = 0;
    while (current != NULL) {
        if ((isbn && strcmp(current->isbn, isbn) == 0) || 
            (title && strcmp(current->title, title) == 0)) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1; // 未找到
}

// 插入图书信息
void insertBook(Book** head,char* isbn,char* title, float price) {
    Book* newBook = createBook(isbn, title, price);
    newBook->next = *head;
    *head = newBook;
}

// 删除图书信息
void deleteBook(Book** head,char* isbn, const char* title) {
    Book* current = *head;
    Book* previous = NULL;
    
    while (current != NULL) {
        if ((isbn && strcmp(current->isbn, isbn) == 0) ||
            (title && strcmp(current->title, title) == 0)) {
            if (previous == NULL) { // 删除头节点
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// 修改图书价格
void modifyPrice(Book* head,char* isbn, float newPrice) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->isbn, isbn) == 0) {
            current->price = newPrice;
            return;
        }
        current = current->next;
    }
    printf("未找到对应ISBN的图书。\n");
}

// 排序图书按价格从低到高
void sortBooksByPrice(Book* head) {
    if (head == NULL) return;
    Book* current;
    Book* next;
    float tempPrice;
    char tempIsbn[20];
    char tempTitle[MAX_TITLE_LENGTH];
    
    for (current = head; current != NULL; current = current->next) {
        for (next = current->next; next != NULL; next = next->next) {
            if (current->price > next->price) {
                // 交换价格
                tempPrice = current->price;
                current->price = next->price;
                next->price = tempPrice;
                
                // 交换ISBN
                strcpy(tempIsbn, current->isbn);
                strcpy(current->isbn, next->isbn);
                strcpy(next->isbn, tempIsbn);
                
                // 交换书名
                strcpy(tempTitle, current->title);
                strcpy(current->title, next->title);
                strcpy(next->title, tempTitle);
            }
        }
    }
}

// 统计图书数量
int countBooks(Book* head) {
    int count = 0;
    Book* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// 打印所有图书信息
void printBooks(Book* head) {
    Book* current = head;
    while (current != NULL) {
        printf("%s\t%s\t%.2f\n", current->isbn, current->title, current->price);
        current = current->next;
    }
}

// 主函数
int main() {
    Book* head = NULL; // 链表头指针
    int choice;
    char isbn[20], title[MAX_TITLE_LENGTH];
    float price;
    int index;
    
    while (1) {
        printf("\n图书信息管理系统\n");
        printf("1. 查找图书\n");
        printf("2. 插入图书\n");
        printf("3. 删除图书\n");
        printf("4. 修改图书价格\n");
        printf("5. 排序图书\n");
        printf("6. 计数图书\n");
        printf("7. 显示所有图书\n");
        printf("0. 退出\n");
        printf("请输入选项: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // 查找
                printf("请输入ISBN或书名：");
                getchar();  
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // 去除换行符
                index = findBook(head, isbn[0] ? isbn : NULL, strlen(title) > 0 ? title : NULL);
                if (index != -1) {
                    printf("找到图书，位置：%d\n", index);
                } else {
                    printf("未找到图书。\n");
                }
                break;
                
            case 2: // 插入
                printf("请输入ISBN: ");
                scanf("%s", isbn);
                printf("请输入书名: ");
                getchar(); // 消耗换行符
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // 去除换行符
                printf("请输入价格: ");
                scanf("%f", &price);
                insertBook(&head, isbn, title, price);
                printf("图书插入成功。\n");
                break;
                
            case 3: // 删除
                printf("请输入要删除的ISBN或书名：");
                getchar();
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0';
                printf("请输入ISBN（可选）：");
                scanf("%s", isbn);
                deleteBook(&head, isbn[0] ? isbn : NULL, strlen(title) > 0 ? title : NULL);
                printf("图书删除成功。\n");
                break;
                
            case 4: // 修改价格
                printf("请输入ISBN: ");
                scanf("%s", isbn);
                printf("请输入新的价格: ");
                scanf("%f", &price);
                modifyPrice(head, isbn, price);
                break;
                
            case 5: // 排序
                sortBooksByPrice(head);
                printf("图书排序完成。\n");
                break;
                
            case 6: // 计数
                printf("图书总数: %d\n", countBooks(head));
                break;
                
            case 7: // 显示所有图书
                printBooks(head);
                break;
                
            case 0: // 退出
                printf("退出系统。\n");
                return 0;
        }
    }
    return 0;
}
