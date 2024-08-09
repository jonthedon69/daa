#include <iostream>
using namespace std;

const int MAX = 10;
int set[MAX];
int solution[MAX];
int targetSum;

void findSubsets(int, int, int);
bool isPromising(int, int, int);

int main() {
    int n, sum = 0;
    cout << "Enter maximum number: ";
    cin >> n;
    cout << "Enter the set in increasing order:\n";
    for (int i = 1; i <= n; i++) {
        cin >> set[i];
        sum += set[i];
    }
    cout << "Enter the maximum subset value (d): ";
    cin >> targetSum;

    if (sum < targetSum || set[1] > targetSum) {
        cout << "No Subset possible";
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
                    cout << set[j] << " ";
                }
            }
            cout << "\n";
        } else {
            solution[i + 1] = 1;
            findSubsets(i + 1, weight + set[i + 1], total - set[i + 1]);
            solution[i + 1] = 0;
            findSubsets(i + 1, weight, total - set[i + 1]);
        }
    }
}

bool isPromising(int i, int weight, int total) {
    return (weight + total >= targetSum) && (weight == targetSum || weight + set[i + 1] <= targetSum);
}