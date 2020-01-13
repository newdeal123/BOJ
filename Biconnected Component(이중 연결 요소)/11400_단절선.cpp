#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int MAX_N=100000+2;
int V,E,cnt=1;
vector<int>adj[MAX_N],discoverd;
vector<pair<int,int>>isCutEdge;

int findCutEdge(int u,int parent)
{
    discoverd[u]=cnt++;
    int ret=discoverd[u];
    for(auto v:adj[u])
    {
        if(v==parent)continue;
        if(!discoverd[v])
        {
            int subtree=findCutEdge(v,u);
            if(subtree>discoverd[u])isCutEdge.push_back({u,v});
            ret=min(ret,subtree);
        }
        else ret=min(ret,discoverd[v]);
    }
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>V>>E;
    discoverd.resize(V+1,0);
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=V;i++)if(!discoverd[i])findCutEdge(i,-1);
    for(auto&i:isCutEdge)if(i.first>i.second)swap(i.first,i.second);
    sort(isCutEdge.begin(),isCutEdge.end());
    cout<<isCutEdge.size()<<"\n";
    for(auto i:isCutEdge)cout<<i.first<<" "<<i.second<<"\n";
}

