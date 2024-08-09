#include <iostream>
using namespace std;
const int MAX = 10;
class AdjMatrix {
    protected: int a[MAX][MAX];
    int n;
    public: void ReadAdj();
    void PrintAdj();
    void Warshall();
};
void AdjMatrix::ReadAdj() {
    cout << "Enter the no of vertices ";
    cin >> n;
    cout << "Enter the adjacency matrix" << endl;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) 
            cin >> a[i][j];
}
void AdjMatrix::PrintAdj() {
    cout << "The transitive closure is\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            cout << a[i][j] << " ";
        cout << endl; 
    }
}
void AdjMatrix::Warshall() {
    for(int k=1; k<=n; k++) 
        for(int i=1; i<=n; i++) 
            for(int j=1; j<=n; j++)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
}
int main() {
    AdjMatrix g1;
    g1.ReadAdj();
    g1.Warshall();
    g1.PrintAdj();
}