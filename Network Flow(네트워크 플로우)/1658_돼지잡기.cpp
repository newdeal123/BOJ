#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_M=1000,MAX_NM=100*1000,MAX_V=MAX_NM+3002,INF=(int)1e9+7;
int S=MAX_V-2,E=MAX_V-1,N,M;

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
    int total = 0;
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
		total += flow;
	}
	return total;
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
    cin>>M>>N;
    for(int i=0;i<M;i++)
    {
        int c;
        cin>>c;
        connect(S,i,c);
    }
    for(int i=MAX_NM;i<MAX_NM+N;i++)
    {
        int cnt,c;
        cin>>cnt;
        vector<int>W(cnt);
        for(int j=0;j<cnt;j++)
        {
            cin>>W[j];
            W[j]-=1;
        }
        cin>>c;
        connect(i,E,c);

        if(i<MAX_NM+N-1)
            for(int j=0;j<M;j++)
        {
            int now=MAX_M*(i-MAX_NM)+j,next=MAX_M*(i-MAX_NM+1)+j;
            connect(now,next,INF);
        }


        for(auto j:W)
        {
            int now=MAX_M*(i-MAX_NM)+j;
            connect(now,i,INF);
            if(i==MAX_NM+N-1)continue;
            for(auto k:W)
            {
                int next=MAX_M*(i-MAX_NM+1)+k;
                if(j==k)continue;
                connect(now,next,INF);
            }
        }
    }
    cout<<networkFlow(S,E);
}
