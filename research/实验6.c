#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10
#define INF INT_MAX

// 定义图的邻接矩阵
int graph[MAX_CITIES][MAX_CITIES];
int dist[MAX_CITIES];
int prev[MAX_CITIES];
int visited[MAX_CITIES];

// Dijkstra算法，计算最短路径
void dijkstra(int start, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }
    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        // 找到当前未访问的最小距离的城市
        int u = -1;
        int minDist = INF;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                u = j;
                minDist = dist[j];
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        // 更新与u相邻的城市的最短距离
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

// 打印最短路径
void printPath(int start, int end) {
    if (end == -1) {
        printf("没有路径\n");
        return;
    }
    if (start == end) {
        printf("%d ", start);
    } else {
        printPath(start, prev[end]);
        printf("%d ", end);
    }
}

int main() {
    int n, m, start, end;
    
    printf("请输入城市数量: ");
    scanf("%d", &n);
    
    // 初始化图的邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }

    printf("请输入交通网络的边数: ");
    scanf("%d", &m);

    printf("请输入每条边的信息 (城市1, 城市2, 时间):\n");
    for (int i = 0; i < m; i++) {
        int u, v, time;
        scanf("%d %d %d", &u, &v, &time);
        graph[u][v] = time;
    }

    printf("请输入起点城市和终点城市: ");
    scanf("%d %d", &start, &end);

    // 执行Dijkstra算法
    dijkstra(start, n);

    // 输出最短时间和路径
    printf("从城市 %d 到城市 %d 的最短时间是: %d\n", start, end, dist[end]);
    printf("最短路径为: ");
    printPath(start, end);
    printf("\n");

    return 0;
}
