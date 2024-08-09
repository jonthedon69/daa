#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

void mergesort(float a[], int , int);
void merge(float a[], int, int, int);

int main() {
    float a[MAX];
    int i, n;
    clock_t start, stop;
    double duration;
    srand((unsigned)time(NULL));
    printf("\nEnter n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) 
        a[i] = (float)rand() / RAND_MAX;

    start = clock();
    mergesort(a, 0, n - 1);
    stop = clock();

    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Duration: %f seconds\n", duration);
}
/*nt main() {
    int a[MAX],b[MAX];
    char ar[MAX];
    int i,n,j;
    clock_t start,stop;
    double duration;
    srand((unsigned)NULL);
    printf("\nEnter n : ");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    a[i]=rand();
    start=clock();
    mergesort(a,0,n-1);
    stop=clock();
    duration=(float)(stop-start)/CLOCKS_PER_SEC;
    printf("\nDuration = %lf",duration);
}*/

void mergesort(float a[], int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(float a[], int low, int mid, int high) {
    float b[MAX];
    int h, i, j, k;
    h = i = low;
    j = mid + 1;
    while((h <= mid) && (j <= high)) {
        if(a[h] < a[j]) 
            b[i++] = a[h++];
        else 
            b[i++] = a[j++];
    }
    if(h > mid) 
        for(k = j; k <= high; k++) 
            b[i++] = a[k];
    else   
        for(k = h; k <= mid; k++) 
            b[i++] = a[k];
    for(k = low; k <= high; k++)
        a[k] = b[k];
}
