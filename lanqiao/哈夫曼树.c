#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// 定义哈夫曼树节点
typedef struct MinHeapNode {
    char data;                   // 存储字符
    unsigned freq;               // 存储字符的频率
    struct MinHeapNode *left, *right;  // 左右子树
} MinHeapNode;

// 定义最小堆
typedef struct MinHeap {
    unsigned size;               // 当前堆的大小
    unsigned capacity;           // 堆的最大容量
    MinHeapNode **array;         // 存储堆节点的数组
} MinHeap;

// 创建一个新的哈夫曼树节点
MinHeapNode* newNode(char data, unsigned freq) {
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// 创建一个最小堆
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// 交换两个节点
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// 最小堆的堆化操作
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

// 检查堆是否只包含一个节点
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// 提取最小节点
MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// 插入一个新的节点
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// 构建最小堆
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

// 创建并构建哈夫曼树
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

// 打印哈夫曼编码
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

// 统计字符出现的频率
void frequencyCount(const char* text, int* freq) {
    while (*text) {
        freq[(unsigned char)(*text)]++;
        text++;
    }
}

// 哈夫曼编码
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

// 译码哈夫曼编码
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
    // 输入的英文文章
    const char* text = "Let life be beautiful like summer flowers";
    printf("Original Text: %s\n\n", text);

    // 生成哈夫曼编码并输出
    printf("Huffman Codes:\n");
    huffmanCoding(text);

    // 假设编码字符串，实际应该从生成的编码映射中获得
    const char* encodedStr = "011101110111";  // 示例编码, 注意：实际编码需要从哈夫曼树中生成
    printf("\nDecoded Text: ");
    
    // 这里根据实际哈夫曼树进行译码
    MinHeapNode* root = buildHuffmanTree((char[]){'L', 'e', 't', ' ', 'l', 'i', 'f', 'b', 'u', 'a', 't', 'k', 's', 'm', 'r', 'w', 'o'}, 
                                         (int[]){1, 1, 1, 3, 2, 2, 1, 2, 3, 2, 1, 1, 1, 1, 2, 1, 1}, 16); // 示例频率
    decodeHuffman(root, encodedStr);

    return 0;
}












