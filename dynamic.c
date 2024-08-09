#include <stdio.h>
#define MAX 30
int V[MAX][MAX];
int keep[MAX][MAX];
int knapsack(int p[], int w[], int n, int M);
int main() {
    int profits[MAX];
    int weights[MAX];
    int n, M, optsoln;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &weights[i]);
    printf("Enter profits:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &profits[i]);
    printf("Knapsack Capacity: ");
    scanf("%d", &M);
    for(int i = 0; i <= M; i++)
        V[0][i] = 0;
    for(int i = 0; i <= n; i++)
        V[i][0] = 0;
    optsoln = knapsack(profits, weights, n, M);
    printf("Solution: %d\n", optsoln);
    return 0;
}
int knapsack(int p[], int w[], int n, int M) {
    int r;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= M; j++) {
            if((w[i] <= j) && (p[i] + V[i-1][j-w[i]] > V[i-1][j])) {
                V[i][j] = V[i-1][j-w[i]] + p[i];
                keep[i][j] = 1;
            } else {
                V[i][j] = V[i-1][j];
                keep[i][j] = 0;
            }
        }
    }
    r = M;
    printf("Items = ");
    for(int i = n; i > 0; i--) {
        if(keep[i][r] == 1) {
            printf("%d ", i);
            r = r - w[i];
        }
    }
    printf("\n");
    return V[n][M];
}
