#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=15,MAX_V=MAX_N*MAX_N+2,INF=987654321;
int N,M,S=MAX_V-1,E=MAX_V-2,tag[5][5]={{10,8,7,5,1},{8,6,4,3,1},{7,4,3,2,1},{5,3,2,2,1},{1,1,1,1,0}};
int goY[4]={0,0,1,-1},goX[4]={1,-1,0,0};

bool is_in_board(int y,int x)
{
    if(y<0||y>N-1||x<0||x>M-1)return false;
    return true;
}
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
    int ret=-INF;
    int totalFlow=0,totalCost=0;
    while (true)
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
            //cout<<i<<" ";
            edge[i]->addFlow(flow);
            totalCost += flow*edge[i]->cost;
        }
       // cout<<", total="<<totalCost<<"\n";
        ret=max(ret,-totalCost);
        totalFlow += flow;
    }
    return (ret==-INF?0:ret);
}
int main()
{
    cin>>N>>M;
    char board[MAX_N][MAX_N];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            cin>>board[i][j];
            if(board[i][j]=='F')board[i][j]='E';
        }

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
            {
                int num=i*M+j;
                if((i+j)%2==0)
                    connect(num,E,1,0);
                else
                {
                    connect(S,num,1,0);
                    for(int k=0;k<4;k++)
                    {
                        int nextY=i+goY[k],nextX=j+goX[k];
                        int nextNum=nextY*M+nextX;
                        if(!is_in_board(nextY,nextX)) continue;
                        connect(num,nextNum,1,-tag[board[i][j]-'A'][board[nextY][nextX]-'A']);
                    }
                }
            }
    cout<<networkFlow(S,E);

}
