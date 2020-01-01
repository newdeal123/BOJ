#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=1000+2;
int N,M,cache[MAX_N];
vector<pair<int,int>>adj[MAX_N];

int f(int u)
{
    int&ret=cache[u];
    if(ret!=-1)return ret;

    for(auto i:adj[u])
    {
        int v=i.first,cost=i.second;
        if(v==1)ret=max(ret,cost);
        else ret=max(ret,f(v)+cost);
    }
    return ret;
}

void output(int u)
{
    cout<<u<<" ";
    int next,ret=0;
    for(auto i:adj[u])
    {
        int v=i.first,cost=i.second;
        if(v==1 && ret<cost)
        {
            ret=cost;
            next=v;
        }
        else if(ret<f(v)+cost)
        {
            ret=f(v)+cost;
            next=v;
        }
    }
    if(next==1){cout<<"1 ";return ;}
    else output(next);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache,-1,sizeof(cache));
    cin>>N>>M;
    while(M--)
    {
        int u,v,dist;
        cin>>u>>v>>dist;
        adj[u].push_back({v,dist});
    }
    cout<<f(1)<<"\n";
    output(1);
}
