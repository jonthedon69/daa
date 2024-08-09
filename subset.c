#include <stdio.h>
#define MAX 10
int set[MAX];
int solution[MAX];
int targetSum;
void findSubsets(int i, int weight, int total);
int isPromising(int i, int weight, int total);
int main() {
    int n, sum = 0;
    printf("Enter maximum number: ");
    scanf("%d", &n);
    printf("Enter the set in increasing order:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &set[i]);
        sum += set[i];
    }
    printf("Enter the maximum subset value (d): ");
    scanf("%d", &targetSum);

    if (sum < targetSum || set[1] > targetSum) {
        printf("No Subset possible\n");
    } else {
        findSubsets(0, 0, sum);
    }
    return 0;
}
void findSubsets(int i, int weight, int total) {
    if (isPromising(i, weight, total)) {
        if (weight == targetSum) {
            for (int j = 1; j <= i; j++) {
                if (solution[j]) {
                    printf("%d ", set[j]);
                }
            }
            printf("\n");
        } else {
            solution[i + 1] = 1;
            findSubsets(i + 1, weight + set[i + 1], total - set[i + 1]);
            solution[i + 1] = 0;
            findSubsets(i + 1, weight, total - set[i + 1]);
        }
    }
}
int isPromising(int i, int weight, int total) {
    return (weight + total >= targetSum) && (weight == targetSum || weight + set[i + 1] <= targetSum);
}
