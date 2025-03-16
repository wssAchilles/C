#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BOOKS 100
#define MAX_NAME_LENGTH 100
struct BOOK
{
    char isbn[20];
    char name[MAX_NAME_LENGTH];
    float price;
};
typedef struct BOOK Book;
int loadBooks(Book *books);
void saveBooks(Book *books, int count);
int findBook(Book *books, int count, char *isbn_or_name);
void insertBook(Book *books, int *count);
void deleteBook(Book *books, int *count, char *isbn);
void sortBooks(Book *books, int count);
void countBooks(int count);
void saveBooks(Book *books, int count)
{
    int i;
    FILE *fp;
    fp = fopen("book.txt", "wb");
    if (fp == NULL)
    {
        printf("无法打开文件进行写入。\n");
        return;
    }
    for (i = 0; i < count; i++)
    {
        fwrite(&books[i], sizeof(Book), 1, fp);
    }
    fclose(fp);
}
int loadBooks(Book *books)
{
    FILE *fp = fopen("book.txt", "rb");
    int count = 0;
    if (fp == NULL)
    {
        printf("无法打开文件进行读取。\n");
        return 0;
    }
    while (fread(&books[count], sizeof(Book), 1, fp) == 1 && count < MAX_BOOKS)
    {
        count++;
    }
    fclose(fp);
    return count;
}
int findBook(Book books[], int count, char *isbn_or_name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].isbn, isbn_or_name)==0||strcmp(books[i].name, isbn_or_name) == 0)
        {
            return i;
        }
    }
    return -1;
}
void insertBook(Book books[], int *count)
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
    saveBooks(books, *count);
    printf("图书已插入。\n");
}
void deleteBook(Book books[], int *count, char *isbn)
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
    saveBooks(books, *count);
    printf("图书已删除。\n");
}
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
void countBooks(int count)
{
    printf("当前图书数量：%d\n", count);
}
int main()
{
    Book books[MAX_BOOKS];
    int count = loadBooks(books);
    int choice;
    char isbn[20];
    while (1)
    {
        printf("\n图书管理系统：\n");
        printf("1. 查询图书\n");
        printf("2. 插入图书\n");
        printf("3. 删除图书\n");
        printf("4. 排序图书\n");
        printf("5. 统计图书数量\n");
        printf("6. 退出\n");
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
            insertBook(books, &count);
            break;

        case 3:
            printf("请输入要删除的图书的ISBN：");
            scanf("%s", isbn);
            deleteBook(books, &count, isbn);
            break;

        case 4:
            sortBooks(books, count);
            saveBooks(books, count);
            printf("图书已按价格排序。\n");
            break;

        case 5:
            countBooks(count);
            break;

        case 6:
            exit(0);

        default:
            printf("无效选择，请重新输入。\n");
        }
    }

    return 0;
}
