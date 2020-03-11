#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
#include <map>
using namespace std;
const int MAX_N=100,MAX_V=MAX_N*5+2,INF=(int)1e9+7;
int S=MAX_V-2,E=MAX_V-1,N,F,D;

struct EDGE
{
    int to,capacity,flow;
    EDGE* rev;
    EDGE(int to,int capacity):to(to),capacity(capacity),flow(0){}
    int getCap(){return capacity-flow;}
    void addFlow(int f)
    {
        flow+=f;
        rev->flow-=f;
    }
};
vector<EDGE*>adj[MAX_V];

int networkFlow(int source,int sink)
{
    int totalFlow = 0;
	while(true)
    {
        vector<int>prev(MAX_V,-1);
		EDGE *edge[MAX_V];
		queue<int> q;
		prev[source]=source;
		q.push(source);

		while(!q.empty() && prev[E] == -1)
        {
			int now = q.front();
			q.pop();
			for(EDGE *e: adj[now]){
				int next = e->to;
				if(e->getCap() > 0 && prev[next] == -1){
					prev[next] = now;
					edge[next] = e;
					q.push(next);
				}
			}
		}
		if(prev[sink] == -1) break;

		int flow = INF;
		for(int i=sink; i!=source; i=prev[i])
			flow = min(flow, edge[i]->getCap());
		for(int i=sink; i!=source; i=prev[i])
			edge[i]->addFlow(flow);
		totalFlow += flow;
	}
	return totalFlow;
}

void connect(int u,int v,int cap)
{
    EDGE*uv=new EDGE(v,cap),*vu=new EDGE(u,0);
    uv->rev=vu,vu->rev=uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>F>>D;
    int inP=MAX_N,outP=MAX_N*2,foodP=MAX_N*3,drinkP=MAX_N*4;
    for(int i=0;i<N;i++)
    {
        int fcnt,dcnt;
        cin>>fcnt>>dcnt;
        while(fcnt--)
        {
            int node;
            cin>>node;
            node-=1;
            connect(foodP+node,inP+i,1);
        }
        while(dcnt--)
        {
            int node;
            cin>>node;
            node-=1;
            connect(outP+i,drinkP+node,1);
        }
    }
    for(int i=0;i<F;i++)
        connect(S,foodP+i,1);
    for(int i=0;i<D;i++)
        connect(drinkP+i,E,1);
    for(int i=0;i<N;i++)
        connect(inP+i,outP+i,1);

    cout<<networkFlow(S,E);
}
