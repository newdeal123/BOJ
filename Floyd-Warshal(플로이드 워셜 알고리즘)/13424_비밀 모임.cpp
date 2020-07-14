#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
const int INF=987654321;
int N,M,K;
int dist[101][101];
vector<int>v;

void floyd()
{
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N>>M;

        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)dist[i][j]=(i==j?0:INF);

        while(M--)
        {
            int u,v,len;
            cin>>u>>v>>len;
            dist[u][v]=min(dist[u][v],len);
            dist[v][u]=min(dist[v][u],len);
        }
        cin>>K;
        v.resize(K);
        for(auto&i:v)cin>>i;
        floyd();
        int fin,finDist=INF;
        for(int i=1;i<=N;i++)
        {
            int sum=0;
           // for(auto j:v)cout<<j<<" to "<<i<<"="<<dist[j][i]<<endl;
            for(auto j:v)sum+=dist[j][i];
            if(finDist>sum){finDist=sum,fin=i;}
        }
        cout<<fin<<"\n";

    }
}
