#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void selection_sort(int arr[], int n) {
    int i,j,min_index,temp;
    for(i=0; i<n-1; i++) {
        min_index = i;
        for(j=i+1; j<n; j++) {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int n, a[10000];
    float duration;
    clock_t start, stop;
    srand((unsigned)time(NULL));
    printf("Enter size ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) 
        a[i] = rand();
    start = clock();
        selection_sort(a, n);
    stop = clock();
    duration = (float)(stop - start) / CLOCKS_PER_SEC;
    printf("Time taken is %f sec", duration);
} 