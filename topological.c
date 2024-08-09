#include <stdio.h>
#define MAX 10
void ReadAdj(int a[MAX][MAX], int* n);
void TopoSort(int a[MAX][MAX], int n, int soln[MAX]);
int Indegree(int a[MAX][MAX], int node, int n);
void PrintTopologicalOrder(int soln[MAX], int n);
int main() {
    int a[MAX][MAX];
    int n;
    int soln[MAX];
    ReadAdj(a, &n);
    TopoSort(a, n, soln);
    PrintTopologicalOrder(soln, n);
    return 0;
}
void ReadAdj(int a[MAX][MAX], int* n) {
    printf("Enter the number of vertices: ");
    scanf("%d", n);
    printf("Enter the Adjacency Matrix:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}
int Indegree(int a[MAX][MAX], int node, int n) {
    int in_deg = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][node] == 1)
            in_deg++;
    }
    return in_deg;
}
void TopoSort(int a[MAX][MAX], int n, int soln[MAX]) {
    int visited[MAX] = {0};
    int indeg[MAX];
    int k = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (visited[j] == 0) {
                indeg[j] = Indegree(a, j, n);
                if (indeg[j] == 0)
                    break;
            }
        }
        soln[k++] = j + 1;
        visited[j] = 1;
        for (int w = 0; w < n; w++) {
            if (a[j][w] == 1)
                a[j][w] = 0;
        }
    }
}
void PrintTopologicalOrder(int soln[MAX], int n) {
    printf("Topological Order:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", soln[i]);
    printf("\n");
}
