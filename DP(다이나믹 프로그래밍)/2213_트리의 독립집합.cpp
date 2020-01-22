#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int MAX_N=10000+2;
int N,cache[MAX_N][2],cost[MAX_N];
bool visited[MAX_N]={0,};
vector<int>adj[MAX_N],bid[MAX_N],ans;

void dfs(int u,int parent)
{
    visited[u]=true;
    if(parent!=0)adj[parent].push_back(u);
    for(auto v:bid[u])
        if(!visited[v])dfs(v,u);
}

int f(int idx,bool mustSkip)
{
    if(adj[idx].size()==0)
    {
        if(mustSkip)return 0;
        else return max(0,cost[idx]);
    }
    int&ret=cache[idx][mustSkip];
    if(ret!=-1)return ret;
    ret=0;

    int sum=0;
    for(auto next:adj[idx])
        sum+=f(next,0);

    ret=max(ret,sum);
    if(!mustSkip)
    {
        int sum=cost[idx];
        for(auto next:adj[idx])
            sum+=f(next,1);
        ret=max(ret,sum);
    }
    return ret;

}

void output(int idx,bool mustSkip)
{
    if(adj[idx].empty())
    {
        if(!mustSkip)ans.push_back(idx);
        return ;
    }
    if(mustSkip)
    {
        for(auto next:adj[idx])output(next,0);
    }
    else
    {
        int sum1=0,sum2=cost[idx];
        for(auto next:adj[idx])sum1+=f(next,0);
        for(auto next:adj[idx])sum2+=f(next,1);
        if(sum1>sum2)
        {
            for(auto next:adj[idx])output(next,0);
        }
        else
        {
            ans.push_back(idx);
            for(auto next:adj[idx])output(next,1);
        }
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>N;
    for(int i=1;i<=N;i++)cin>>cost[i];
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
        bid[u].push_back(v);
        bid[v].push_back(u);
    }
    dfs(1,0);

    cout<<f(1,0)<<"\n";
    output(1,0);
    sort(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<" ";
}
