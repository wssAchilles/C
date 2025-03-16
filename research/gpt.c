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
        printf("\nͼ�����ϵͳ��\n");
        printf("1. ��ѯͼ��\n");
        printf("2. ����ͼ��\n");
        printf("3. ɾ��ͼ��\n");
        printf("4. �޸�ͼ��۸�\n");
        printf("5. ����ͼ��\n");
        printf("6. ͳ��ͼ������\n");
        printf("7. �˳�\n");
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
            insertBook(books, &count, "book.txt");
            break;

        case 3:
            printf("������Ҫɾ����ͼ���ISBN��");
            scanf("%s", isbn);
            deleteBook(books, &count, isbn, "book.txt");
            break;

        case 4:
            printf("������Ҫ�޸ĵ�ͼ���ISBN��");
            scanf("%s", isbn);
            printf("�������µļ۸�");
            scanf("%f", &price);
            modifyBook(books, count, isbn, price, "book.txt");
            break;

        case 5:
            sortBooks(books, count);
            saveBooks(books, count, "book.txt");
            printf("ͼ���Ѱ��۸�����\n");
            break;

        case 6:
            countBooks(count);
            break;

        case 7:
            exit(0);

        default:
            printf("��Чѡ�����������롣\n");
        }
    }

    return 0;
}

// ����ͼ������
int loadBooks(Book books[], const char *filename)
{
    FILE *file = fopen(filename, "r");
    int count = 0;
    if (file == NULL)
    {
        printf("�޷����ļ���\n");
        return 0;
    }

    while (fscanf(file, "%s %s %f", books[count].isbn, books[count].name, &books[count].price) == 3)
    {
        count++;
    }
    fclose(file);
    return count;
}

// ����ͼ������
void saveBooks(Book books[], int count, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("�޷����ļ���\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s %s %.2f\n", books[i].isbn, books[i].name, books[i].price);
    }
    fclose(file);
}

// ����ͼ��
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

// ����ͼ��
void insertBook(Book books[], int *count, const char *filename)
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
    saveBooks(books, *count, filename);
    printf("ͼ���Ѳ��롣\n");
}

// ɾ��ͼ��
void deleteBook(Book books[], int *count, const char *isbn, const char *filename)
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
    saveBooks(books, *count, filename);
    printf("ͼ����ɾ����\n");
}

// �޸�ͼ��۸�
void modifyBook(Book books[], int count, const char *isbn, float new_price, const char *filename)
{
    int index = findBook(books, count, isbn);
    if (index == -1)
    {
        printf("δ�ҵ�ָ����ͼ�顣\n");
        return;
    }
    books[index].price = new_price;
    saveBooks(books, count, filename);
    printf("ͼ��۸����޸ġ�\n");
}

// ����ͼ��
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

// ͳ��ͼ������
void countBooks(int count)
{
    printf("�ļ��е�ͼ������Ϊ��%d\n", count);
}