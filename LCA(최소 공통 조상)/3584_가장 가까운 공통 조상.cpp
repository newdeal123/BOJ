#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N=10000+2;
int N,root,depth[MAX_N],parent[MAX_N][21];
bool is_root[MAX_N];
vector<int>adj[MAX_N];

void dfs(int now)
{
    for(auto next:adj[now])
        if(depth[next]==-1)
        {
            parent[next][0]=now;
            depth[next]=depth[now]+1;
            dfs(next);
        }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<MAX_N;i++)adj[i].clear();
        memset(is_root,true,sizeof(is_root));
        cin>>N;
        for(int i=0;i<N-1;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            is_root[b]=false;
        }
        for(int i=1;i<=N;i++)if(is_root[i])root=i;
        memset(parent,-1,sizeof(parent));
        memset(depth,-1,sizeof(depth));
        depth[root]=0;
        dfs(root);

        for(int j=0;j<21;j++)
            for(int i=1;i<=N;i++)
                if(parent[i][j]!=-1)
                    parent[i][j+1]=parent[parent[i][j]][j];

        int u,v;
        cin>>u>>v;
        if(depth[u]<depth[v]) swap(u,v);
        int diff=depth[u]-depth[v];
        for(int i=0;diff;i++)
        {
            if(diff%2)u=parent[u][i];
            diff/=2;
        }

        if(u!=v)
        {
            for(int i=20;i>=0;i--)
            {
                if(parent[u][i]!=-1 && parent[u][i] != parent[v][i])
                {
                    u=parent[u][i];
                    v=parent[v][i];
                }
            }
            u=parent[u][0];
        }
        cout<<u<<"\n";

    }
}
