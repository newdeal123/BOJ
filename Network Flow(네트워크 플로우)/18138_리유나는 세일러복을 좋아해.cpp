#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,cnt=0;
vector<int>a,b;
vector<vector<int>>adj;
int aMatch[1001],bMatch[1001],visited[1001];

bool dfs(int u)
{
    if(visited[u])return false;
    visited[u]=true;
    for(auto v:adj[u])
    {
        if(aMatch[v]==-1||dfs(aMatch[v]))
        {
            aMatch[v]=u;
            bMatch[u]=v;
            return true;
        }
    }
    return false;
}


int main()
{
    cin>>n>>m;
    a.resize(n),b.resize(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];

    adj.resize(m);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(((double)b[i]>=(double)a[j]*(0.5) && (double)b[i]<=(double)a[j]*(0.75)) ||
               (b[i]>=a[j] &&  (double)b[i]<=(double)a[j]*(1.25)) )
                adj[i].push_back(j);
    }

    memset(aMatch,-1,sizeof(aMatch));
    memset(bMatch,-1,sizeof(bMatch));

    for(int i=0;i<m;i++)
    {
        memset(visited,0,sizeof(visited));
        if(dfs(i)) cnt++;
    }
    cout<<cnt;
}
