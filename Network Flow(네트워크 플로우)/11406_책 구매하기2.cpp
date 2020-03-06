#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=100,MAX_V=MAX_N*2+3,INF=987654321;
int S=MAX_V-2,E=MAX_V-1,N,M,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int networkFlow(int source,int sink)
{
    memset(flow,0,sizeof(flow));
    int totalSum=0;
    while(true)
    {
        vector <int> parent(MAX_V,-1);
        queue <int> q;
        parent[source]=source;
        q.push(source);
        while(!q.empty()&&parent[sink]==-1)
        {
            int now=q.front();q.pop();
            for(auto next:adj[now])
            {
                if(capacity[now][next]-flow[now][next]>0 && parent[next]==-1)
                {
                    q.push(next);
                    parent[next]=now;
                }
            }
        }
        if(parent[sink]==-1) break;
        int sum=INF;
        for(int p=sink;p!=source;p=parent[p])
            sum=min(capacity[parent[p]][p]-flow[parent[p]][p],sum);
        for(int p=sink;p!=source;p=parent[p])
        {
            flow[parent[p]][p]+=sum;
            flow[p][parent[p]]-=sum;
        }
        totalSum+=sum;
    }
    return totalSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    for(int i=MAX_N;i<N+MAX_N;i++)
    {
        cin>>capacity[i][E];
        adj[i].push_back(E);
        adj[E].push_back(i);
    }
    for(int i=0;i<M;i++)
    {
        cin>>capacity[S][i];
        adj[S].push_back(i);
        adj[i].push_back(S);
    }
    for(int i=0;i<M;i++)
    {
        for(int j=MAX_N;j<N+MAX_N;j++)
        {
            cin>>capacity[i][j];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    cout<<networkFlow(S,E)<<"\n";


}
