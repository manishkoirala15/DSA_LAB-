#include <stdio.h>

int parent[10];

int find(int i) {
    while (parent[i] != 0)
        i = parent[i];
    return i;
}

int union_set(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, edges = 1;
    int min, cost = 0;
    int a, b, u, v;
    int graph[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize parent array
    for (int i = 0; i < n; i++)
        parent[i] = 0;

    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = 999;
        }
        graph[i][i] = 999;  // ignore self loops
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edges < n) {
        min = 999;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] < min) {
                    min = graph[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (union_set(u, v)) {
            printf("Edge %d: (%d, %d) with cost %d\n", edges, a, b, min);
            cost += min;
            edges++;
        }

        graph[a][b] = graph[b][a] = 999;
    }

    printf("Total cost of Minimum Spanning Tree: %d\n", cost);

    return 0;
}
