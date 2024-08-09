#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void ReadAdj(int adj[MAX][MAX], int *n);
void Dijkstras(int adj[MAX][MAX], int n, int s);
int Extract_Min(int dist[], int S[], int n);

int main() {
    int adj[MAX][MAX];
    int n, s;

    ReadAdj(adj, &n);
    printf("Enter the starting vertex: ");
    scanf("%d", &s);
    Dijkstras(adj, n, s - 1);  // Adjusting for zero-based indexing

    return 0;
}

void ReadAdj(int adj[MAX][MAX], int *n) {
    printf("Enter the number of vertices: ");
    scanf("%d", n);
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < *n; i++) {
        for(int j = 0; j < *n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0 && i != j) {
                adj[i][j] = INFINITY;  // Setting non-diagonal 0 values to INFINITY
            }
        }
    }
}

void Dijkstras(int adj[MAX][MAX], int n, int s) {
    int dist[MAX], S[MAX];
    int u, v;

    // Initialization
    for(int i = 0; i < n; i++) {
        S[i] = 0;
        dist[i] = adj[s][i];
    }
    S[s] = 1;
    dist[s] = 0;

    // Main Dijkstra's algorithm loop
    for(int i = 1; i < n; i++) {
        u = Extract_Min(dist, S, n);
        S[u] = 1;

        for(v = 0; v < n; v++) {
            if(!S[v] && adj[u][v] && dist[u] != INFINITY && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    printf("Shortest paths from vertex %d:\n", s + 1);  // Adjusting back to one-based indexing
    for(int i = 0; i < n; i++) {
        if(i != s) {
            printf("%d: %d\n", i + 1, dist[i]);  // Adjusting back to one-based indexing
        }
    }
}

int Extract_Min(int dist[], int S[], int n) {
    int min = INFINITY, min_index = -1;

    for(int i = 0; i < n; i++) {
        if(!S[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}
