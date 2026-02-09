#include <stdio.h>
#include <limits.h>   // for INT_MAX
#include <stdbool.h>  // for bool type
#define MAX 100
#define INF INT_MAX

int findMinDistance(int dist[], bool visited[], int n) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int src, int n) {
    int dist[MAX];
    bool visited[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinDistance(dist, visited, n);
        if (u == -1) break; // no reachable vertex
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source (%d)\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("%d\tINF\n", i);
        else printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int graph[MAX][MAX];
    int n, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, n);
    return 0;
}
