#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// ������������ڵ�
typedef struct MinHeapNode {
    char data;                   // �洢�ַ�
    unsigned freq;               // �洢�ַ���Ƶ��
    struct MinHeapNode *left, *right;  // ��������
} MinHeapNode;

// ������С��
typedef struct MinHeap {
    unsigned size;               // ��ǰ�ѵĴ�С
    unsigned capacity;           // �ѵ��������
    MinHeapNode **array;         // �洢�ѽڵ������
} MinHeap;

// ����һ���µĹ��������ڵ�
MinHeapNode* newNode(char data, unsigned freq) {
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// ����һ����С��
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// ���������ڵ�
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// ��С�ѵĶѻ�����
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// �����Ƿ�ֻ����һ���ڵ�
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// ��ȡ��С�ڵ�
MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// ����һ���µĽڵ�
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// ������С��
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

// ������������������
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newNode(data[i], freq[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);

    while (!isSizeOne(minHeap)) {
        MinHeapNode* left = extractMin(minHeap);
        MinHeapNode* right = extractMin(minHeap);

        MinHeapNode* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// ��ӡ����������
void printHuffmanCodes(MinHeapNode* root, int* arr, int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// ͳ���ַ����ֵ�Ƶ��
void frequencyCount(const char* text, int* freq) {
    while (*text) {
        freq[(unsigned char)(*text)]++;
        text++;
    }
}

// ����������
void huffmanCoding(const char* text) {
    int freq[256] = {0};
    frequencyCount(text, freq);

    char data[256];
    int frequency[256];
    int size = 0;

    for (int i = 0; i < 256; ++i) {
        if (freq[i]) {
            data[size] = (char)i;
            frequency[size] = freq[i];
            ++size;
        }
    }

    MinHeapNode* root = buildHuffmanTree(data, frequency, size);

    int arr[MAX_TREE_HT], top = 0;
    printHuffmanCodes(root, arr, top);
}

// �������������
void decodeHuffman(MinHeapNode* root, const char* encodedStr) {
    MinHeapNode* current = root;
    for (int i = 0; encodedStr[i] != '\0'; ++i) {
        if (encodedStr[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!current->left && !current->right) {
            printf("%c", current->data);
            current = root;
        }
    }
    printf("\n");
}

int main() {
    // �����Ӣ������
    const char* text = "Let life be beautiful like summer flowers";
    printf("Original Text: %s\n\n", text);

    // ���ɹ��������벢���
    printf("Huffman Codes:\n");
    huffmanCoding(text);

    // ��������ַ�����ʵ��Ӧ�ô����ɵı���ӳ���л��
    const char* encodedStr = "011101110111";  // ʾ������, ע�⣺ʵ�ʱ�����Ҫ�ӹ�������������
    printf("\nDecoded Text: ");
    
    // �������ʵ�ʹ���������������
    MinHeapNode* root = buildHuffmanTree((char[]){'L', 'e', 't', ' ', 'l', 'i', 'f', 'b', 'u', 'a', 't', 'k', 's', 'm', 'r', 'w', 'o'}, 
                                         (int[]){1, 1, 1, 3, 2, 2, 1, 2, 3, 2, 1, 1, 1, 1, 2, 1, 1}, 16); // ʾ��Ƶ��
    decodeHuffman(root, encodedStr);

    return 0;
}












