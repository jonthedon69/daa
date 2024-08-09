#include <iostream>
using namespace std;

int count = 0;
const int MAX = 20;

void Display(int [], int);
void nQueens(int);
int Place(int [], int);

int main() {
    int n;
    cout << "Enter the number of Queens: ";
    cin >> n;
    nQueens(n);
    cout << "The solution to Queen's Problem is: " << count << endl;
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
        if (x[k] < n)
            if (k == n - 1) {
                count++;
                Display(x, n);
            } else {
                k++;
                x[k] = -1;
            }
        else
            k--;
    }
}

int Place(int x[], int k) {
    int i;
    for (i = 0; i < k; i++)
        if (x[i] == x[k] || (x[i] - x[k] == i - k))
            return 0;
    return 1;
}

void Display(int x[], int n) {
    char Chessboard[MAX][MAX];
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            Chessboard[i][j] = 'x';
    for (i = 0; i < n; i++)
        Chessboard[i][x[i]] = 'Q';
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << Chessboard[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}