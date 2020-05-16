#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
const int MAX_N=500000+2,INF=987654321;
int N,W;
vector<int>adj[MAX_N];
bool visited[MAX_N]={0,};
double n=0,sum=0;

void dfs(int now,double d)
{
    visited[now]=true;
    bool leaf=true;
    int size=(now==1?adj[now].size():adj[now].size()-1);
    for(auto next:adj[now])
    {
        if(!visited[next])
        {
            leaf=false;
            dfs(next,d*1.0/(double)size);
        }
    }
    if(leaf)
    {
        n++;
        sum+=W*d;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>W;
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1.0);
    cout<<fixed;
    cout.precision(5);
    cout<<sum/n;
}
