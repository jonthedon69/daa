#include <stdio.h>
#define MAX 10

void ReadAdj(int adj[MAX][MAX], int *n);
void PrintAdj(int adj[MAX][MAX], int n);
void Warshall(int adj[MAX][MAX], int n);

int main() {
    int adj[MAX][MAX];
    int n;

    ReadAdj(adj, &n);
    Warshall(adj, n);
    PrintAdj(adj, n);

    return 0;
}

void ReadAdj(int adj[MAX][MAX], int *n) {
    printf("Enter the number of vertices: ");
    scanf("%d", n);
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < *n; i++)
        for(int j = 0; j < *n; j++)
            scanf("%d", &adj[i][j]);
}

void PrintAdj(int adj[MAX][MAX], int n) {
    printf("The transitive closure is:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

void Warshall(int adj[MAX][MAX], int n) {
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
}
