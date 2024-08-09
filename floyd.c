#include <stdio.h>
#include <stdlib.h>
int mini(int , int );
int Floyds(int D[10][10], int n);
int main() {
    int n, i, j, D[10][10];
    printf("Read the no. of nodes: ");
    scanf("%d", &n);
    printf("Read the weighted matrix:\n");
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &D[i][j]);
    Floyds(D,n);
    printf("\nThe all pair shortest path is\n");
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
}

int mini(int a, int b) {
    if (a < b) 
        return a;
    else    
        return b;
}
int Floyds(int D[10][10], int n) {
    int i,j,k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                D[i][j] = mini(D[i][j], D[i][k]+D[k][j]);
}