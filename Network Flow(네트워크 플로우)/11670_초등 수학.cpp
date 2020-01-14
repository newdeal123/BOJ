#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
const int MAX_N=2500+2;
typedef long long ll;
int N,aMatch[MAX_N*3],bMatch[MAX_N*3];
vector<int>adj[MAX_N];
vector<pair<int,int>>input;
bool visited[MAX_N];
map<ll,int>cache;

bool dfs(int u)
{
    if(visited[u])return false;
    visited[u]=true;
    for(auto v:adj[u])
        if(bMatch[v]==-1||dfs(bMatch[v]))
    {
        bMatch[v]=u;
        aMatch[u]=v;
        return true;
    }
    return false;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(aMatch,-1,sizeof(aMatch));
    memset(bMatch,-1,sizeof(bMatch));
    cin>>N;
    int cnt=0;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        input.push_back({a,b});
        if(cache.find(a+b)==cache.end())cache.insert({a+b,cnt++});
        if(cache.find(a-b)==cache.end())cache.insert({a-b,cnt++});
        if(cache.find((ll)a*b)==cache.end())cache.insert({(ll)a*b,cnt++});
        adj[i].push_back(cache[a+b]);
        adj[i].push_back(cache[a-b]);
        adj[i].push_back(cache[(ll)a*b]);
    }
    cnt=0;
    for(int i=0;i<N;i++)
    {
        memset(visited,0,sizeof(visited));
        if(dfs(i))cnt++;
    }
    if(cnt!=N)cout<<"impossible";
    else
    {
        for(int i=0;i<N;i++)
        {
            int a=input[i].first,b=input[i].second;
            if(cache[a+b]==aMatch[i])cout<<a<<" + "<<b<<" = "<<a+b<<"\n";
            else if(cache[a-b]==aMatch[i])cout<<a<<" - "<<b<<" = "<<a-b<<"\n";
            else if(cache[(ll)a*b]==aMatch[i])cout<<a<<" * "<<b<<" = "<<(ll)a*b<<"\n";
        }
    }

}
