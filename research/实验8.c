#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        heapify(arr, i, 0);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // 生成随机数组
    int arr[SIZE];
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100000;
    }

    // 记录快速排序的时间
    int arr1[SIZE];
    for (int i = 0; i < SIZE; i++) arr1[i] = arr[i];
    clock_t start = clock();
    quickSort(arr1, 0, SIZE-1);
    clock_t end = clock();
    printf("QuickSort: %lf milliseconds\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    // 记录Shell排序的时间
    int arr2[SIZE];
    for (int i = 0; i < SIZE; i++) arr2[i] = arr[i];
    start = clock();
    shellSort(arr2, SIZE);
    end = clock();
    printf("ShellSort: %lf milliseconds\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    // 记录堆排序的时间
    int arr3[SIZE];
    for (int i = 0; i < SIZE; i++) arr3[i] = arr[i];
    start = clock();
    heapSort(arr3, SIZE);
    end = clock();
    printf("HeapSort: %lf milliseconds\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    // 记录冒泡排序的时间
    int arr4[SIZE];
    for (int i = 0; i < SIZE; i++) arr4[i] = arr[i];
    start = clock();
    bubbleSort(arr4, SIZE);
    end = clock();
    printf("BubbleSort: %lf milliseconds\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    return 0;
}
