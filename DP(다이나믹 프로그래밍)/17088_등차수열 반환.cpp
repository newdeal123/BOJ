#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=1000,MAX_V=MAX_N*2+2,INF=987654321;
int N,M;
int in(int n){return n*2;}
int out(int n){return n*2+1;}


struct Edge
{
    int to, capacity, flow, cost;
    Edge *rev;
    Edge(int to=-1, int capacity=0, int cost=0) : to(to),capacity(capacity),cost(cost),flow(0){}
    void addFlow(int f)
    {
        flow+=f;
        rev->flow-=f;
    }
    int getCap() {return capacity-flow;}
};
vector<Edge*> adj[MAX_V];

void connect(int u,int v,int cap,int cost)
{
    Edge *uv = new Edge(v,cap,cost),*vu = new Edge(u,0,-cost);
    uv->rev = vu;
    vu->rev = uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}

int networkFlow(int source,int sink)
{
    int totalFlow=0,totalCost=0;
    int go=2;
    while (go--)
    {
        queue<int> q;
        vector<int>prev(MAX_V,-1),dist(MAX_V,INF);
        bool inQ[MAX_V]={0,};
        Edge *edge[MAX_V];

        dist[source] = 0;
        inQ[source] = true;
        q.push(source);

        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            inQ[now] = false;

            for (Edge *e : adj[now])
            {
                int next = e->to;
                if (e->getCap() > 0 && dist[next] > dist[now] + e->cost)
                {
                    prev[next] = now;
                    edge[next] = e;
                    dist[next] = dist[now] + e->cost;
                    if (!inQ[next])
                    {
                        q.push(next);
                        inQ[next] = true;
                    }
                }
            }
        }

        if (prev[sink] == -1) break;

        int flow = INF;
        for (int i = sink; i != source; i = prev[i])
            flow = min(flow, edge[i]->getCap());
        for (int i = sink; i != source; i = prev[i])
        {
            edge[i]->addFlow(flow);
            totalCost += edge[i]->cost;
        }

        totalFlow += flow;
    }
    return totalCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=2;
    while(cin>>N>>M)
    {
        for(int i=0;i<MAX_V;i++)adj[i].clear();
        for(int i=0;i<N;i++)connect(in(i),out(i),1,0);
        while(M--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            connect(out(a-1),in(b-1),1,c);
        }

        cout<<networkFlow(out(0),in(N-1))<<"\n";
    }

}
