#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=5000+2,INF=987654321;
int V,E,P;
vector<pair<int,int>>adj[MAX_N];

int dijkstra(int start,int fin)
{
    priority_queue <pair<int,int>> pq;
    vector <int> dist(V+1,INF);
    dist[start]=0;
    pq.push(make_pair(0,start));
    while(!pq.empty())
    {
        int Pcost=-pq.top().first;
        int now=pq.top().second;
        pq.pop();
        if(Pcost>dist[now]) continue;
        for(auto i:adj[now])
        {
            int next=i.first,nextDist=Pcost+i.second;
            if(nextDist<dist[next])
            {
                dist[next]=nextDist;
                pq.push(make_pair(-nextDist,next));
            }
        }
    }
    return dist[fin];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>V>>E>>P;
    while(E--)
    {
        int u,v,dist;
        cin>>u>>v>>dist;
        adj[u].push_back({v,dist});
        adj[v].push_back({u,dist});
    }
    //cout<<dijkstra(1,V)<<"="<<dijkstra(1,P)<<"+"<<dijkstra(P,V)<<endl;
    if(dijkstra(1,V)==dijkstra(1,P)+dijkstra(P,V)) cout<<"SAVE HIM";
    else cout<<"GOOD BYE";
}
