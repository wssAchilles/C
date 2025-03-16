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
        printf("�޷����ļ�����д�롣\n");
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
        printf("�޷����ļ����ж�ȡ��\n");
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
        printf("ͼ���������޷����롣\n");
        return;
    }
    printf("������ISBN��");
    scanf("%s", books[*count].isbn);
    printf("������������");
    scanf("%s", books[*count].name);
    printf("������۸�");
    scanf("%f", &books[*count].price);
    (*count)++;
    saveBooks(books, *count);
    printf("ͼ���Ѳ��롣\n");
}
void deleteBook(Book books[], int *count, char *isbn)
{
    int index = findBook(books, *count, isbn);
    if (index == -1)
    {
        printf("δ�ҵ�ָ����ͼ�顣\n");
        return;
    }
    for (int i = index; i < *count - 1; i++)
    {
        books[i] = books[i + 1];
    }
    (*count)--;
    saveBooks(books, *count);
    printf("ͼ����ɾ����\n");
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
    printf("��ǰͼ��������%d\n", count);
}
int main()
{
    Book books[MAX_BOOKS];
    int count = loadBooks(books);
    int choice;
    char isbn[20];
    while (1)
    {
        printf("\nͼ�����ϵͳ��\n");
        printf("1. ��ѯͼ��\n");
        printf("2. ����ͼ��\n");
        printf("3. ɾ��ͼ��\n");
        printf("4. ����ͼ��\n");
        printf("5. ͳ��ͼ������\n");
        printf("6. �˳�\n");
        printf("ѡ�������");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("������Ҫ��ѯ��ISBN��������");
            scanf("%s", isbn);
            int index = findBook(books, count, isbn);
            if (index != -1)
            {
                printf("�ҵ�ͼ�飺ISBN: %s, ����: %s, �۸�: %.2f\n", books[index].isbn, books[index].name, books[index].price);
            }
            else
            {
                printf("δ�ҵ�ָ����ͼ�顣\n");
            }
            break;

        case 2:
            insertBook(books, &count);
            break;

        case 3:
            printf("������Ҫɾ����ͼ���ISBN��");
            scanf("%s", isbn);
            deleteBook(books, &count, isbn);
            break;

        case 4:
            sortBooks(books, count);
            saveBooks(books, count);
            printf("ͼ���Ѱ��۸�����\n");
            break;

        case 5:
            countBooks(count);
            break;

        case 6:
            exit(0);

        default:
            printf("��Чѡ�����������롣\n");
        }
    }

    return 0;
}
