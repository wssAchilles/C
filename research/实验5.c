#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // �������

// �ڽӱ��������
typedef struct Node {
    int vertex;  // �ýڵ����Ľ��
    struct Node* next;  // ָ����һ���ڽӽ��
} Node;

// ͼ�Ľṹ��
typedef struct Graph {
    Node* adjList[MAX_VERTICES];  // �ڽӱ�
    int visited[MAX_VERTICES];     // ���ʱ�־
} Graph;

// ����ͼ
void initGraph(Graph* g) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->adjList[i] = NULL;  // ��ʼ��ÿ�������ڽ�����Ϊ��
        g->visited[i] = 0;  // ��ʼ�����н��δ����
    }
}

// ������
void addEdge(Graph* g, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
}

// ������ȱ��� (DFS)
void DFS(Graph* g, int vertex) {
    g->visited[vertex] = 1;  // ��Ǹý��Ϊ�ѷ���
    printf("%d ", vertex);    // ������
    Node* temp = g->adjList[vertex];
    while (temp != NULL) {
        if (!g->visited[temp->vertex]) {
            DFS(g, temp->vertex);  // �ݹ����δ���ʵ��ڽӽ��
        }
        temp = temp->next;
    }
}

// ������ȱ��� (BFS)
void BFS(Graph* g, int startVertex) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    
    // ������н��Ϊδ����
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->visited[i] = 0;
    }
    
    queue[rear++] = startVertex;  // ����ʼ������
    g->visited[startVertex] = 1;
    
    while (front != rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);  // ������
        
        Node* temp = g->adjList[currentVertex];
        while (temp != NULL) {
            if (!g->visited[temp->vertex]) {
                queue[rear++] = temp->vertex;  // ��δ���ʵ��ڽӽ�����
                g->visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    Graph g;
    initGraph(&g);
    
    // ����ͼ��������10����㣬���0-9
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 0, 4);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 5);
    addEdge(&g, 2, 6);
    addEdge(&g, 3, 7);
    addEdge(&g, 4, 8);
    addEdge(&g, 5, 9);
    addEdge(&g, 6, 0);
    addEdge(&g, 7, 8);
    addEdge(&g, 8, 9);
    addEdge(&g, 9, 7);
    addEdge(&g, 3, 9);
    addEdge(&g, 2, 5);
    addEdge(&g, 6, 3);
    addEdge(&g, 0, 9);
    addEdge(&g, 4, 3);
    addEdge(&g, 5, 7);

    printf("������ȱ��� (DFS): ");
    DFS(&g, 0);  // �ӽ��0��ʼDFS
    printf("\n");

    // ��շ��ʱ�־
    for (int i = 0; i < MAX_VERTICES; i++) {
        g.visited[i] = 0;
    }

    printf("������ȱ��� (BFS): ");
    BFS(&g, 0);  // �ӽ��0��ʼBFS
    printf("\n");

    return 0;
}
