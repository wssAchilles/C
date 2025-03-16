#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_NAME_LENGTH 100

typedef struct
{
    char isbn[20];
    char name[MAX_NAME_LENGTH];
    float price;
} Book;

int loadBooks(Book books[], const char *filename);
void saveBooks(Book books[], int count, const char *filename);
int findBook(Book books[], int count, const char *isbn_or_name);
void insertBook(Book books[], int *count, const char *filename);
void deleteBook(Book books[], int *count, const char *isbn, const char *filename);
void modifyBook(Book books[], int count, const char *isbn, float new_price, const char *filename);
void sortBooks(Book books[], int count);
void countBooks(int count);

int main()
{
    Book books[MAX_BOOKS];
    int count = loadBooks(books, "book.txt");

    int choice;
    char isbn[20];
    char name[MAX_NAME_LENGTH];
    float price;

    while (1)
    {
        printf("\n图书管理系统：\n");
        printf("1. 查询图书\n");
        printf("2. 插入图书\n");
        printf("3. 删除图书\n");
        printf("4. 修改图书价格\n");
        printf("5. 排序图书\n");
        printf("6. 统计图书数量\n");
        printf("7. 退出\n");
        printf("选择操作：");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("请输入要查询的ISBN或书名：");
            scanf("%s", isbn);
            int index = findBook(books, count, isbn);
            if (index != -1)
            {
                printf("找到图书：ISBN: %s, 书名: %s, 价格: %.2f\n", books[index].isbn, books[index].name, books[index].price);
            }
            else
            {
                printf("未找到指定的图书。\n");
            }
            break;

        case 2:
            insertBook(books, &count, "book.txt");
            break;

        case 3:
            printf("请输入要删除的图书的ISBN：");
            scanf("%s", isbn);
            deleteBook(books, &count, isbn, "book.txt");
            break;

        case 4:
            printf("请输入要修改的图书的ISBN：");
            scanf("%s", isbn);
            printf("请输入新的价格：");
            scanf("%f", &price);
            modifyBook(books, count, isbn, price, "book.txt");
            break;

        case 5:
            sortBooks(books, count);
            saveBooks(books, count, "book.txt");
            printf("图书已按价格排序。\n");
            break;

        case 6:
            countBooks(count);
            break;

        case 7:
            exit(0);

        default:
            printf("无效选择，请重新输入。\n");
        }
    }

    return 0;
}

// 加载图书数据
int loadBooks(Book books[], const char *filename)
{
    FILE *file = fopen(filename, "r");
    int count = 0;
    if (file == NULL)
    {
        printf("无法打开文件。\n");
        return 0;
    }

    while (fscanf(file, "%s %s %f", books[count].isbn, books[count].name, &books[count].price) == 3)
    {
        count++;
    }
    fclose(file);
    return count;
}

// 保存图书数据
void saveBooks(Book books[], int count, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("无法打开文件。\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s %s %.2f\n", books[i].isbn, books[i].name, books[i].price);
    }
    fclose(file);
}

// 查找图书
int findBook(Book books[], int count, const char *isbn_or_name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].isbn, isbn_or_name) == 0 || strcmp(books[i].name, isbn_or_name) == 0)
        {
            return i;
        }
    }
    return -1;
}

// 插入图书
void insertBook(Book books[], int *count, const char *filename)
{
    if (*count >= MAX_BOOKS)
    {
        printf("图书已满，无法插入。\n");
        return;
    }
    printf("请输入ISBN：");
    scanf("%s", books[*count].isbn);
    printf("请输入书名：");
    scanf("%s", books[*count].name);
    printf("请输入价格：");
    scanf("%f", &books[*count].price);
    (*count)++;
    saveBooks(books, *count, filename);
    printf("图书已插入。\n");
}

// 删除图书
void deleteBook(Book books[], int *count, const char *isbn, const char *filename)
{
    int index = findBook(books, *count, isbn);
    if (index == -1)
    {
        printf("未找到指定的图书。\n");
        return;
    }
    for (int i = index; i < *count - 1; i++)
    {
        books[i] = books[i + 1];
    }
    (*count)--;
    saveBooks(books, *count, filename);
    printf("图书已删除。\n");
}

// 修改图书价格
void modifyBook(Book books[], int count, const char *isbn, float new_price, const char *filename)
{
    int index = findBook(books, count, isbn);
    if (index == -1)
    {
        printf("未找到指定的图书。\n");
        return;
    }
    books[index].price = new_price;
    saveBooks(books, count, filename);
    printf("图书价格已修改。\n");
}

// 排序图书
void sortBooks(Book books[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (books[j].price > books[j + 1].price)
            {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

// 统计图书数量
void countBooks(int count)
{
    printf("文件中的图书数量为：%d\n", count);
}