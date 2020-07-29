#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int MAX_N=123456+2;
int N;
vector<pair<char,int>>v;
vector<int>adj[MAX_N];
bool visited[MAX_N]={0,};

ll dfs(int now)
{
    ll ret=(v[now].first=='S'?1:-1)*v[now].second;
    visited[now]=true;

    for(auto next:adj[now])
    {
        if(visited[next])continue;
        ret+=dfs(next);
    }
    return max((ll)0,ret);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    v.push_back({'S',0}),v.push_back({'S',0});
    for(int u=2;u<=N;u++)
    {
        char c;
        int n,j;
        cin>>c>>n>>j;
        v.push_back({c,n});
        adj[u].push_back(j);
        adj[j].push_back(u);
    }
    cout<<dfs(1);
}
