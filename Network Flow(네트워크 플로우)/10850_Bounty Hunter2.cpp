#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;
const int MAX_N=1000+2;
int N,M,aMatch[MAX_N],bMatch[MAX_N];
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
    cin.tie(0);
    cin>>N;
    memset(aMatch,-1,sizeof(aMatch));
    memset(bMatch,-1,sizeof(bMatch));
    for(int i=0;i<N;i++)
    {
        cin>>M;
        while(M--)
        {
            int j;
            cin>>j;
            adj[i].push_back(j);
        }
    }

    int cnt=0;
    for(int i=0;i<N;i++)
    {
        memset(visited,0,sizeof(visited));
        cnt+=dfs(i);
    }
    cout<<N-cnt;

}
