#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=987654321;
const int MAX_N=100000+2;
int N,M,K,S,P,Q;
ll cost[MAX_N]={0,};
vector <int> jombie,adj[MAX_N];

int BFS()
{
    int visited[MAX_N]={0,};
    queue<int>q;
    for(auto i:jombie)
    {
        q.push(i);
        visited[i]=1;
        cost[i]=INF;
    }
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(auto next:adj[now])
        {
            if(!visited[next]&& visited[now]<=S)
            {
                visited[next]=visited[now]+1;
                q.push(next);
                cost[next]=Q;
            }
        }
    }
    for(int i=1;i<=N;i++)if(!cost[i])cost[i]=P;
}

ll dijkstra()
{
    priority_queue <pair<ll,int>> pq;
    vector <ll> dist(N+1,LLONG_MAX-100);
    dist[1]=0;
    pq.push(make_pair(0,1));
    while(!pq.empty())
    {
        ll Pcost=-pq.top().first;
        int now=pq.top().second;
        pq.pop();
        if(Pcost>dist[now]) continue;
        for(auto next:adj[now])
        {
            //cout<<now<<"to"<<next<<endl;
            if(cost[next]==INF) continue;
            if(Pcost+cost[next]<dist[next])
            {
                dist[next]=Pcost+cost[next];
                pq.push(make_pair(-(Pcost+cost[next]),next));
            }
        }
    }
    return dist[N]-cost[N];
}

int main()
{
    cin>>N>>M>>K>>S>>P>>Q;
    jombie.resize(K);
    for(int i=0;i<K;i++)cin>>jombie[i];
    while(M--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS();
    cout<<dijkstra();
}
