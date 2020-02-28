#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;
const int MAX_N=300+2;
int N,M,K1,K2,aMatch[MAX_N],bMatch[MAX_N],cnt=0;
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
    for(int i=0;i<MAX_N;i++)adj[i].clear();
    for(int i=0;i<num;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b);
    }
    int ret=0;
    for(int i=0;i<N;i++)
    {
        memset(visited,0,sizeof(visited));
        ret+=dfs(i);
    }
    return ret;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M>>K1>>K2;
    int cnt1=0,cnt2=0;
    cnt1=solve(K1),cnt2=solve(K2);
    if(cnt1<cnt2)cout<<"네 다음 힐딱이";
    else cout<<"그만 알아보자";
}
