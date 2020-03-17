#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=100+2,MAX_V=MAX_N*MAX_N*2,INF=987654321;
int N,M;
char board[MAX_N][MAX_N];
int goY[4]={0,0,1,-1},goX[4]={1,-1,0,0};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M)return false;
    return true;
}

int in(int n){return n*2;}
int out(int n){return n*2+1;}
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
int num(int y,int x){return (y-1)*M+x;}

int main()
{
    cin>>N>>M;
    int S,E;
    for(int i=1;i<=N;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=M;j++)
        {
            board[i][j]=s[j-1];
            if(board[i][j]=='K')S=num(i,j);
            else if(board[i][j]=='H')E=num(i,j);
            connect(in(num(i,j)),out(num(i,j)),1);
        }
    }

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
    {
        if(board[i][j]=='#'||board[i][j]=='H')continue;
        for(int k=0;k<4;k++)
        {
            int nextY=i+goY[k],nextX=j+goX[k];
            int u=num(i,j),v=num(nextY,nextX);
            if(!is_in_board(nextY,nextX)||board[nextY][nextX]=='#')continue;
            if(board[i][j]=='K'&&board[nextY][nextX]=='H'){cout<<-1;return 0;}
            connect(out(u),in(v),1);
        }
    }

    cout<<networkFlow(out(S),in(E));
}
