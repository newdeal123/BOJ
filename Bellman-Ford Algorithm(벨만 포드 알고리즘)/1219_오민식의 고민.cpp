#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
typedef long long ll;
const ll MY_MAX=9223372036854775807/2;
int N,S,E,M,cash[100+2];
vector<pair<int,int>>adj[100+2];
bool visited[100+2]={0,},toCheck[100+2];

vector<ll>bellmanFord(int start)
{
    vector<ll>upper(N,MY_MAX);
    upper[start]=-cash[start];
    bool updated=false;
    for(int i=0;i<N;i++)
    {
        updated=false;
        for(int now=0;now<N;now++)
            for(auto j:adj[now])
        {
            int next=j.first,cost=j.second-cash[next];
            if(upper[now]!=MY_MAX&&upper[next]>upper[now]+cost)
            {
                upper[next]=upper[now]+cost;
                updated=true;
                if(i==N-1)toCheck[now]=true;
            }
        }
        if(!updated)break;
    }
    return upper;
}

void dfs(int u)
{
    visited[u]=true;
    for(auto i:adj[u])
    {
        int v=i.first;
        if(!visited[v])dfs(v);
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>S>>E>>M;
    while(M--)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
    }
    for(int i=0;i<N;i++)cin>>cash[i];
    vector<ll>ans=bellmanFord(S);

    memset(visited,0,sizeof(visited));
    for(int i=0;i<N;i++)if(toCheck[i]&&!visited[i])dfs(i);
    if(ans[E]==MY_MAX)cout<<"gg";
    else if(visited[E])cout<<"Gee";
    else cout<<-ans[E];
}
