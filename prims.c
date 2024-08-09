#include <stdio.h>

int a, b, u, v, i, j, n, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the weight adjacency matrix\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;  // 999 represents infinity
            }
        }
    }

    visited[1] = 1;
    printf("\n");

    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            if (visited[i] != 0) {
                for (j = 1; j <= n; j++) {
                    if (cost[i][j] < min) {
                        if (visited[j] == 0) {  // Ensures we're adding new vertex to the tree
                            min = cost[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
        }
        
        if (visited[b] == 0) {
            printf("\nEdge %d: (%d, %d) cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}
