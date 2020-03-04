#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;
const int MAX_N=2000+2;
int N,M,aMatch[MAX_N],bMatch[MAX_N];
bool visited[MAX_N];
vector<int> adj[MAX_N],arr;

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
    cin>>N>>M;
    memset(aMatch,-1,sizeof(aMatch));
    memset(bMatch,-1,sizeof(bMatch));
    for(int i=0;i<N;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        if(c=='c')arr.push_back(a-1);
    }
    while(M--)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
    }

    int cnt=0;
    for(auto i:arr)
    {
        memset(visited,0,sizeof(visited));
        cnt+=dfs(i);
    }
    cout<<N-cnt;

}
