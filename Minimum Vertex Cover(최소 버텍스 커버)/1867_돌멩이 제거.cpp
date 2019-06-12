#include <bits/stdc++.h>
using namespace std;
const int MAX_N=500+2;
int N,K,aMatch[MAX_N],bMatch[MAX_N];
vector<int>adj[MAX_N];
bool visited[MAX_N];

bool dfs(int now)
{
    if(visited[now]) return false;
    visited[now]=true;

    for(auto next:adj[now])
    {
        if(bMatch[next]==-1 || dfs(bMatch[next]))
        {
            bMatch[next]=now;
            aMatch[now]=next;
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>N>>K;
    memset(bMatch,-1,sizeof(bMatch));
    for(int i=0;i<K;i++)
    {
        int y,x;
        cin>>y>>x;
        adj[y].push_back(x);
    }
    int sum=0;
    for(int i=1;i<=N;i++)
    {
        memset(visited,false,sizeof(visited));
        if(dfs(i))sum++;
    }
    cout<<sum;
}
