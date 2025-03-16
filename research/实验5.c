#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // 最大结点数

// 邻接表的链表结点
typedef struct Node {
    int vertex;  // 该节点代表的结点
    struct Node* next;  // 指向下一个邻接结点
} Node;

// 图的结构体
typedef struct Graph {
    Node* adjList[MAX_VERTICES];  // 邻接表
    int visited[MAX_VERTICES];     // 访问标志
} Graph;

// 创建图
void initGraph(Graph* g) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->adjList[i] = NULL;  // 初始化每个结点的邻接链表为空
        g->visited[i] = 0;  // 初始化所有结点未访问
    }
}

// 创建边
void addEdge(Graph* g, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
}

// 深度优先遍历 (DFS)
void DFS(Graph* g, int vertex) {
    g->visited[vertex] = 1;  // 标记该结点为已访问
    printf("%d ", vertex);    // 输出结点
    Node* temp = g->adjList[vertex];
    while (temp != NULL) {
        if (!g->visited[temp->vertex]) {
            DFS(g, temp->vertex);  // 递归访问未访问的邻接结点
        }
        temp = temp->next;
    }
}

// 广度优先遍历 (BFS)
void BFS(Graph* g, int startVertex) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    
    // 标记所有结点为未访问
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->visited[i] = 0;
    }
    
    queue[rear++] = startVertex;  // 将起始结点入队
    g->visited[startVertex] = 1;
    
    while (front != rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);  // 输出结点
        
        Node* temp = g->adjList[currentVertex];
        while (temp != NULL) {
            if (!g->visited[temp->vertex]) {
                queue[rear++] = temp->vertex;  // 将未访问的邻接结点入队
                g->visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    Graph g;
    initGraph(&g);
    
    // 构造图，假设有10个结点，编号0-9
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

    printf("深度优先遍历 (DFS): ");
    DFS(&g, 0);  // 从结点0开始DFS
    printf("\n");

    // 清空访问标志
    for (int i = 0; i < MAX_VERTICES; i++) {
        g.visited[i] = 0;
    }

    printf("广度优先遍历 (BFS): ");
    BFS(&g, 0);  // 从结点0开始BFS
    printf("\n");

    return 0;
}
