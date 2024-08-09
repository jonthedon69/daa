#include <iostream>
using namespace std;
const int infinity=9999;
const int MAX=10;
class AdjMatrix
{
    private:int a[MAX][MAX];
            int n;
            int Extract_Min(int []);
            int d[MAX];
    public:void ReadAdj();
           void Dijkstras(int);
};
void AdjMatrix::ReadAdj()
{
        cout << "Enter the number of vertices:";
        cin >> n;
        cout << "Enter the adjacency matrix:" << endl;
        for(int i=1; i<=n; i++) 
                for(int j=1; j<=n; j++)
                        cin >> a[i][j];
}
void AdjMatrix::Dijkstras(int s) 
{
        int S[MAX];
        int u, v, i;
        for(i=1; i<=n; i++) 
        {
                S[i]=0;
                d[i]=a[s][i];
        }
        S[s]=1;
        d[s]=1;
        i=2;
        while(i<=n) 
        {
                u=Extract_Min(S);
                S[u]=1;
                i++;
                for(v=1; v<=n; v++)
                {
                        if((d[u]+a[u][v]<d[v])&&!S[v])
                                d[v]=d[u]+a[u][v];
                }
        }
        for(i=1; i<=n; i++) 
                if(i!=s)
                        cout << i <<":"<< d[i] << endl;
}
int AdjMatrix::Extract_Min(int S[]) 
{
        int i,j=1,min;
        min=infinity;
        for(i=1; i<=n; i++)
        {
                if((d[i]<min) && (!S[i]))
                {
                        min = d[i];
                        j=i;
                }
        }
        return (j);
}
int main() {
        AdjMatrix g1;
        g1.ReadAdj();
        int s;
        cout << "Enter starting vertex:";
        cin >> s;
        g1.Dijkstras(s);
        return 0;
}