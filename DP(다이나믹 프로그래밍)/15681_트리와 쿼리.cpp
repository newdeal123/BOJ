#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAX_N=1e5+2;
int N,R,Q,cache[MAX_N];
vector<int> adj[MAX_N],tree[MAX_N];
bool visited[MAX_N]={0,};

void dfs(int now)
{
    visited[now]=true;
    for(auto next:adj[now])
        if(!visited[next])
    {
        dfs(next);
        tree[now].push_back(next);
    }
}

int f(int now)
{
    int&ret=cache[now];
    if(ret!=-1)return ret;
    ret=1;

    for(auto next:tree[now])
        ret+=f(next);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>R>>Q;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(R);
    while(Q--)
    {
        int u;
        cin>>u;
        cout<<f(u)<<"\n";
    }
}
