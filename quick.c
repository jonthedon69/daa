#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

void quicksort(int[], int, int);

int main() {
    int a[MAX];
    long j;
    float duration;
    clock_t start, end;
    srand((unsigned)time(NULL));
    for(int n=0; n<MAX; n=n+1000) {
        for(int i=0; i<n; i++) 
            a[i] = rand();
        start = clock();
        for(j=0; j<100; j++) {
            quicksort(a, 0, n-1);
        }
        end = clock();
        duration = (float)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t%lf\n", n, duration/100);
    }
    return 0;
}

void quicksort(int a[], int p, int r) {
    int i, temp, pivot, j;
    if(p < r) {
        i = p;
        j = r;
        pivot = a[p];
        while (1)
        {
            i++;
            while(pivot > a[i] && i < r) 
                i++;
            while(pivot < a[j])
                j--;
            if(i < j) 
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else    
                break;
        }
        a[p] = a[j];
        a[j] = pivot;
        quicksort(a, p, j-1);
        quicksort(a, j+1, r);
    }
}












