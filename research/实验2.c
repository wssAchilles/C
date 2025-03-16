#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100

// ͼ����Ϣ�ṹ��
typedef struct Book {
    char isbn[20];        // ISBN
    char title[MAX_TITLE_LENGTH]; // ����
    float price;          // �۸�
    struct Book* next;    // �������һ���ڵ�
}Book;

// ����һ���µ�ͼ��ڵ�
Book* createBook(char* isbn,char* title, float price) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->isbn, isbn);
    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->next = NULL;
    return newBook;
}

// ����ͼ�飬����ͼ���λ�ã���0��ʼ��������
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
    return -1; // δ�ҵ�
}

// ����ͼ����Ϣ
void insertBook(Book** head,char* isbn,char* title, float price) {
    Book* newBook = createBook(isbn, title, price);
    newBook->next = *head;
    *head = newBook;
}

// ɾ��ͼ����Ϣ
void deleteBook(Book** head,char* isbn, const char* title) {
    Book* current = *head;
    Book* previous = NULL;
    
    while (current != NULL) {
        if ((isbn && strcmp(current->isbn, isbn) == 0) ||
            (title && strcmp(current->title, title) == 0)) {
            if (previous == NULL) { // ɾ��ͷ�ڵ�
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

// �޸�ͼ��۸�
void modifyPrice(Book* head,char* isbn, float newPrice) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->isbn, isbn) == 0) {
            current->price = newPrice;
            return;
        }
        current = current->next;
    }
    printf("δ�ҵ���ӦISBN��ͼ�顣\n");
}

// ����ͼ�鰴�۸�ӵ͵���
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
                // �����۸�
                tempPrice = current->price;
                current->price = next->price;
                next->price = tempPrice;
                
                // ����ISBN
                strcpy(tempIsbn, current->isbn);
                strcpy(current->isbn, next->isbn);
                strcpy(next->isbn, tempIsbn);
                
                // ��������
                strcpy(tempTitle, current->title);
                strcpy(current->title, next->title);
                strcpy(next->title, tempTitle);
            }
        }
    }
}

// ͳ��ͼ������
int countBooks(Book* head) {
    int count = 0;
    Book* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// ��ӡ����ͼ����Ϣ
void printBooks(Book* head) {
    Book* current = head;
    while (current != NULL) {
        printf("%s\t%s\t%.2f\n", current->isbn, current->title, current->price);
        current = current->next;
    }
}

// ������
int main() {
    Book* head = NULL; // ����ͷָ��
    int choice;
    char isbn[20], title[MAX_TITLE_LENGTH];
    float price;
    int index;
    
    while (1) {
        printf("\nͼ����Ϣ����ϵͳ\n");
        printf("1. ����ͼ��\n");
        printf("2. ����ͼ��\n");
        printf("3. ɾ��ͼ��\n");
        printf("4. �޸�ͼ��۸�\n");
        printf("5. ����ͼ��\n");
        printf("6. ����ͼ��\n");
        printf("7. ��ʾ����ͼ��\n");
        printf("0. �˳�\n");
        printf("������ѡ��: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // ����
                printf("������ISBN��������");
                getchar();  
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // ȥ�����з�
                index = findBook(head, isbn[0] ? isbn : NULL, strlen(title) > 0 ? title : NULL);
                if (index != -1) {
                    printf("�ҵ�ͼ�飬λ�ã�%d\n", index);
                } else {
                    printf("δ�ҵ�ͼ�顣\n");
                }
                break;
                
            case 2: // ����
                printf("������ISBN: ");
                scanf("%s", isbn);
                printf("����������: ");
                getchar(); // ���Ļ��з�
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // ȥ�����з�
                printf("������۸�: ");
                scanf("%f", &price);
                insertBook(&head, isbn, title, price);
                printf("ͼ�����ɹ���\n");
                break;
                
            case 3: // ɾ��
                printf("������Ҫɾ����ISBN��������");
                getchar();
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0';
                printf("������ISBN����ѡ����");
                scanf("%s", isbn);
                deleteBook(&head, isbn[0] ? isbn : NULL, strlen(title) > 0 ? title : NULL);
                printf("ͼ��ɾ���ɹ���\n");
                break;
                
            case 4: // �޸ļ۸�
                printf("������ISBN: ");
                scanf("%s", isbn);
                printf("�������µļ۸�: ");
                scanf("%f", &price);
                modifyPrice(head, isbn, price);
                break;
                
            case 5: // ����
                sortBooksByPrice(head);
                printf("ͼ��������ɡ�\n");
                break;
                
            case 6: // ����
                printf("ͼ������: %d\n", countBooks(head));
                break;
                
            case 7: // ��ʾ����ͼ��
                printBooks(head);
                break;
                
            case 0: // �˳�
                printf("�˳�ϵͳ��\n");
                return 0;
        }
    }
    return 0;
}
