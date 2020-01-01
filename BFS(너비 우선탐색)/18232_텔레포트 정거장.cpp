#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=300000+2;
int N,M,S,E,dX[2]={-1,1};
vector<int>adj[MAX_N];

int bfs()
{
    int visited[MAX_N]={0,};
    queue<int>q;
    q.push(S);
    visited[S]=1;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        if(now==E)return visited[now]-1;

        for(auto next:adj[now])
        {
            if(!visited[next])
            {
                visited[next]=visited[now]+1;
                q.push(next);
            }
        }
        for(int i=0;i<2;i++)
        {
            int next=now+dX[i];
            if(next<1||next>N||visited[next])continue;
            visited[next]=visited[now]+1;
            q.push(next);
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M>>S>>E;
    while(M--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<bfs();
}
