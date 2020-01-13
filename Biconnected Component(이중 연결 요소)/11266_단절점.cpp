#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int MAX_N=10000+2;
int V,E,cnt=1;
vector<int>adj[MAX_N],discoverd;
vector<bool>isCutVertex;

int findCutVertex(int u,bool isRoot)
{
    discoverd[u]=cnt++;
    int ret=discoverd[u],child=0;
    for(auto v:adj[u])
    {
        if(!discoverd[v])
        {
            child++;
            int subtree=findCutVertex(v,false);
            if(!isRoot&&subtree>=discoverd[u])isCutVertex[u]=true;
            ret=min(ret,subtree);
        }
        else ret=min(ret,discoverd[v]);
    }
    if(isRoot&&child>=2)isCutVertex[u]= true;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>V>>E;
    discoverd.resize(V+1,0),isCutVertex.resize(V+1,0);
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=V;i++)if(!discoverd[i])findCutVertex(i,true);
    int ans=0;
    for(auto i:isCutVertex)if(i)ans++;
    cout<<ans<<"\n";
    for(int i=1;i<=V;i++)if(isCutVertex[i])cout<<i<<" ";
}

