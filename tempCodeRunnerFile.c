#include <stdio.h>

#define MAX 10

typedef struct {
    int a[MAX][MAX];
    int n;
    int soln[MAX];
    int visited[MAX];
    int indeg[MAX];
} Topo;

void ReadAdj(Topo* top);
int Indegree(Topo* top, int node);
void TopoSort(Topo* top);

int main() {
    Topo top;
    ReadAdj(&top);
    TopoSort(&top);
    return 0;
}

void ReadAdj(Topo* top) {
    printf("Enter the number of vertices: ");
    scanf("%d", &(top->n));
    printf("Enter the Adjacency Matrix:\n");
    for(int i = 1; i <= top->n; i++) {
        for(int j = 1; j <= top->n; j++) {
            scanf("%d", &(top->a[i][j]));
        }
    }
    for(int i = 1; i <= top->n; i++) {
        top->visited[i] = 0;
    }
}

void TopoSort(Topo* top) {
    int k = 1;
    int j;
    for(int i = 1; i <= top->n; i++) {
        for(j = 1; j <= top->n; j++) {
            if(top->visited[j] == 0) {
                top->indeg[j] = Indegree(top, j);
                if(top->indeg[j] == 0)
                    break;
            }
        }
        top->soln[k++] = j;
        top->visited[j] = 1;
        for(int w = 1; w <= top->n; w++) {
            if(top->a[j][w] == 1)
                top->a[j][w] = 0;
        }
        printf("Topological Order: ");
        for(int i = 1; i <= top->n; i++)
            printf("%d ", top->soln[i]);
        printf("\n");
    }
}

int Indegree(Topo* top, int node) {
    int in_deg = 0;
    for(int i = 1; i <= top->n; i++) {
        if(top->a[i][node] == 1)
            in_deg++;
    }
    return in_deg;
}
