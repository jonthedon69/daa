#include <stdio.h>
int main() {
    float weight[50], profit[50], ratio[50], Totalvalue = 0, temp, capacity, amount;
    int n, i, j;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter Weight and Profit for item[%d]: ", i);
        scanf("%f %f", &weight[i], &profit[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);
    for(i = 0; i < n; i++) 
        ratio[i] = profit[i] / weight[i];
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) { 
            if(ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    printf("Knapsack problem using Greedy Algorithm:\n");
    for(i = 0; i < n; i++) {
        if(weight[i] > capacity)
            break;
        else {
            Totalvalue += profit[i];
            capacity -= weight[i];
        }
    }
    if(i < n) 
        Totalvalue += (ratio[i] * capacity);
    printf("The maximum value is: %f\n", Totalvalue);
    return 0;
}
