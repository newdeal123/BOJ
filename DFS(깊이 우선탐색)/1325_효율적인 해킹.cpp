#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N=10000+2;
int N,M;
vector<int>adj[MAX_N];
bool visited[MAX_N];

int dfs(int u)
{
    visited[u]=true;
    int ret=0;
    for(auto v:adj[u])
        if(!visited[v])ret+=dfs(v)+1;
    return ret;
}


void dfsAll()
{
    vector<int>sum(N+1,0);
    for(int i=1;i<=N;i++)
    {
        memset(visited,0,sizeof(visited));
        sum[i]=dfs(i);
    }

    int maxN=0;
    for(int i=1;i<=N;i++)maxN=max(maxN,sum[i]);
    for(int i=1;i<=N;i++)if(maxN==sum[i])cout<<i<<" ";
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    while(M--)
    {
        int u,v;
        cin>>v>>u;
        adj[u].push_back(v);
    }
    dfsAll();
}
