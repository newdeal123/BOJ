#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=400;
int V,P,capacity[MAX_N*2+2][MAX_N*2+2],flow[MAX_N*2+2][MAX_N*2+2];
vector<int>adj[MAX_N*2+2];

int in(int n) {return n;}
int out(int n) {return n+MAX_N;}

int networkFlow(int source,int sink)
{
    memset(flow,0,sizeof(flow));

    int totalSum=0;
    while(true)
    {
        vector<int>parent(MAX_N*2+2,-1);
        queue<int>q;
        parent[source]=source;
        q.push(source);
        while(!q.empty() && parent[sink]==-1)
        {
            int now=q.front();
            q.pop();
            for(auto next:adj[now])
            {
                if(parent[next]==-1 && capacity[now][next]-flow[now][next]>0 )
                {
                    parent[next]=now;
                    q.push(next);
                }
            }
        }
        if(parent[sink]==-1) break;
        int sum=INF;
        for(int p=sink;p!=source;p=parent[p])
            sum=min(sum,capacity[parent[p]][p]-flow[parent[p]][p]);
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

    for(int i=1;i<=MAX_N;i++)
    {
        capacity[in(i)][out(i)]=1;
        adj[in(i)].push_back(out(i));
        adj[out(i)].push_back(in(i));
    }
    cin>>V>>P;
    while(P--)
    {
        int a,b;
        cin>>a>>b;
        adj[out(a)].push_back(in(b));
        adj[out(b)].push_back(in(a));
        adj[in(b)].push_back(out(a));
        adj[in(a)].push_back(out(b));
        capacity[out(a)][in(b)]=1;
        capacity[out(b)][in(a)]=1;
    }
    cout<<networkFlow(out(1),in(2));
}
