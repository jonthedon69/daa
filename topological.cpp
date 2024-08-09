#include <iostream>
using namespace std;
const int MAX = 10;
class Topo
{
    private:
        int a[MAX][MAX];
        int n;
        int soln[MAX];
        int visited[MAX];
        int indeg[MAX];
    public:
        void ReadAdj();
        int Indegree(int);
        void TopoSort();
};
void Topo::ReadAdj()
{
    cout << "Enter the number of vertices:";
    cin >> n;
    cout << "Enter the Adjacency Matrix:" << endl;
    for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++) 
            cin >> a[i][j];
    for(int i=1; i<=n; i++) 
        visited[i]=0;
}
void Topo::TopoSort() {
    int k=1;
    int j;
    for(int i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            if(visited[j]==0) {
                indeg[j] = Indegree(j);
                if(indeg[j]==0)
                    break;
            }
        }
        soln[k++]=j;
        visited[j]=1;
        for(int w=1; w<=n; w++) {
            if(a[j][w]==1)
                a[j][w]=0;
        }
        cout << "Topological Order:";
        for(i=1; i<=n; i++)
            cout << soln[i] << " ";
        cout << endl;
    }
}
int Topo::Indegree(int node) {
    int in_deg=0;
    for(int i=1; i<=n; i++)
        if(a[i][node]==1)
            in_deg++;
    return in_deg;
}
int main() {
    Topo top;
    top.ReadAdj();
    top.TopoSort();
    return 0;
}