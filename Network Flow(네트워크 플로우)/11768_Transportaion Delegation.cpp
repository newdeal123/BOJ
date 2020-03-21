#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
#include <map>
using namespace std;
const int MAX_N=3000,MAX_V=MAX_N+2,INF=(int)1e9+7;
int s,r,f,t,S=MAX_V-2,E=MAX_V-1,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];
map<string,int>cache;

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

void connect(int u,int v,int cap)
{
    capacity[u][v]=cap;
    capacity[v][u]=0;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s>>r>>f>>t;
    int cnt=0;
    for(int i=0;i<r;i++)
    {
        string tmp;
        cin>>tmp;
        cache[tmp]=cnt++;
        connect(S,cache[tmp],1);
    }
    for(int i=0;i<f;i++)
    {
        string tmp;
        cin>>tmp;
        cache[tmp]=cnt++;
        connect(cache[tmp],E,1);
    }
    int mid=s;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int left=s+i,right=s+t+i;
        connect(left,right,1);
        for(int j=0;j<n;j++)
        {
            string tmp;
            cin>>tmp;
            if(cache.find(tmp)==cache.end())
                cache[tmp]=cnt++;
            connect(cache[tmp],left,1);
            connect(right,cache[tmp],1);
        }
    }
    cout<<networkFlow(S,E);
}
