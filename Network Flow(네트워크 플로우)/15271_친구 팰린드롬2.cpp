#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;
const int MAX_N=200+2;
int N,M,aMatch[MAX_N],bMatch[MAX_N],cnt=0;
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

int solve(int num)
{
    memset(aMatch,-1,sizeof(aMatch));
    memset(bMatch,-1,sizeof(bMatch));
    for(int i=0;i<num;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(a%2==b%2)continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ret=0;
    for(int i=0;i<N;i++)
    {
        memset(visited,0,sizeof(visited));
        ret+=dfs(i);
    }
    return min(N,ret+1);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    cout<<solve(M);
}
