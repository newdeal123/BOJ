#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;
const int MAX_N=200+2;
int N,M,K,aMatch[MAX_N],bMatch[MAX_N],cnt=0;
bool visited[MAX_N];
vector<int> adj[MAX_N];

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(bMatch,-1,sizeof(bMatch));
    cin>>N>>M>>K;
    for(int i=0;i<K;i++)
    {
        int y,x;
        cin>>y>>x;
        adj[y].push_back(x);
    }
    for(int i=1;i<=N;i++)
    {
        memset(visited,0,sizeof(visited));
        if(dfs(i)) cnt++;
    }
    cout<<N+M-cnt;
}
