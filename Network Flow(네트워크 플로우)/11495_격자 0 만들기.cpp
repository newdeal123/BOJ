#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=50,MAX_V=MAX_N*MAX_N+2,INF=987654321;
int N,M,S=MAX_V-2,E=MAX_V-1,goY[4]={0,0,1,-1},goX[4]={1,-1,0,0};

bool is_in_board(int y,int x)
{
    if(y<0||y>N-1||x<0||x>M-1)return false;
    return true;
}

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

		while(!q.empty() && prev[sink] == -1)
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
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<MAX_V;i++)adj[i].clear();
        cin>>N>>M;
        int board[MAX_N][MAX_N],sum=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                    cin>>board[i][j];
                    sum+=board[i][j];
            }
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                int num=i*M+j;
                if((i+j)%2==0){
                    connect(num,E,board[i][j]);
                }
                else{
                    connect(S,num,board[i][j]);
                    for(int k=0;k<4;k++){
                        int nextY=i+goY[k],nextX=j+goX[k];
                        int nextNum=nextY*M+nextX;
                        if(!is_in_board(nextY,nextX)) continue;
                        connect(num,nextNum,INF);
                    }
                }
            }
        cout<<sum-networkFlow(S,E)<<"\n";
    }
}
