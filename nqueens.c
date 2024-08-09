#include <stdio.h>
int count = 0;
#define MAX 20

void Display(int x[], int n);
void nQueens(int n);
int Place(int x[], int k);

int main() {
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d", &n);
    nQueens(n);
    printf("The solution to the Queen's Problem is: %d\n", count);
    return 0;
}

void nQueens(int n) {
    int x[MAX];
    int k;
    x[0] = -1;
    k = 0;
    while (k >= 0) {
        x[k] = x[k] + 1;
        while (x[k] < n && !Place(x, k))
            x[k] = x[k] + 1;
        if (x[k] < n) {
            if (k == n - 1) {
                count++;
                Display(x, n);
            } else {
                k++;
                x[k] = -1;
            }
        } else
            k--;
    }
}

int Place(int x[], int k) {
    int i;
    for (i = 0; i < k; i++) {
        if (x[i] == x[k] || (x[i] - x[k] == i - k) || (x[k] - x[i] == i - k))
            return 0;
    }
    return 1;
}

void Display(int x[], int n) {
    char Chessboard[MAX][MAX];
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            Chessboard[i][j] = 'x';
        }
    }
    for (i = 0; i < n; i++) {
        Chessboard[i][x[i]] = 'Q';
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", Chessboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
