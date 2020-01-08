#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int MAX_N=10000+2;
int N;
vector<pair<int,int>>adj[MAX_N];
bool visited[MAX_N];


pair<int,int> dfs(int u,int dist)
{
    visited[u]=true;
    pair<int,int>ret={u,dist};
    for(auto i:adj[u])
    {
        int v=i.first,cost=i.second;
        if(!visited[v])
        {
            pair<int,int>tmp=dfs(v,dist+cost);
            if(ret.second<tmp.second)
                ret=tmp;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int u,v,dist;
    while(cin>>u)
    {
        cin>>v>>dist;
        adj[u].push_back({v,dist});
        adj[v].push_back({u,dist});
    }
    memset(visited,0,sizeof(visited));
    pair<int,int>start=dfs(1,0);
    memset(visited,0,sizeof(visited));
    cout<<dfs(start.first,0).second;
}
