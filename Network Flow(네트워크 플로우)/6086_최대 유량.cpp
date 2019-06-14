#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=50+3;
int V,capacity[MAX_N][MAX_N],flow[MAX_N][MAX_N];
vector<int> adj[MAX_N];

int getN(char c)
{
    if(isupper(c)) return c-'A';
    else return c-'a'+('z'-'a'+1);
}

int networkFlow(int source,int sink)
{
    memset(flow,0,sizeof(flow));
    int totalSum=0;
    while(true)
    {
        vector <int> parent(MAX_N,-1);
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
    cin>>V;
    for(int i=0;i<V;i++)
    {
        char a,b;
        int n;
        cin>>a>>b>>n;
        a=getN(a),b=getN(b);
        capacity[a][b]+=n;
        capacity[b][a]+=n;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<networkFlow(getN('A'),getN('Z'));
}
