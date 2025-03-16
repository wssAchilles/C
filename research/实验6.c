#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10
#define INF INT_MAX

// ����ͼ���ڽӾ���
int graph[MAX_CITIES][MAX_CITIES];
int dist[MAX_CITIES];
int prev[MAX_CITIES];
int visited[MAX_CITIES];

// Dijkstra�㷨���������·��
void dijkstra(int start, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }
    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        // �ҵ���ǰδ���ʵ���С����ĳ���
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

        // ������u���ڵĳ��е���̾���
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

// ��ӡ���·��
void printPath(int start, int end) {
    if (end == -1) {
        printf("û��·��\n");
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
    
    printf("�������������: ");
    scanf("%d", &n);
    
    // ��ʼ��ͼ���ڽӾ���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }

    printf("�����뽻ͨ����ı���: ");
    scanf("%d", &m);

    printf("������ÿ���ߵ���Ϣ (����1, ����2, ʱ��):\n");
    for (int i = 0; i < m; i++) {
        int u, v, time;
        scanf("%d %d %d", &u, &v, &time);
        graph[u][v] = time;
    }

    printf("�����������к��յ����: ");
    scanf("%d %d", &start, &end);

    // ִ��Dijkstra�㷨
    dijkstra(start, n);

    // ������ʱ���·��
    printf("�ӳ��� %d ������ %d �����ʱ����: %d\n", start, end, dist[end]);
    printf("���·��Ϊ: ");
    printPath(start, end);
    printf("\n");

    return 0;
}
