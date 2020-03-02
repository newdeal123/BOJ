#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;
const int MAX_N=100+2;
int N,M,S,V,aMatch[MAX_N],bMatch[MAX_N];
bool visited[MAX_N];
vector<pair<double,double>>gopher,hole;
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

double getDist(pair<double,double>a,pair<double,double>b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>N)
    {
        cin>>M>>S>>V;
        gopher.clear(),hole.clear();
        for(int i=0;i<MAX_N;i++)adj[i].clear();
        memset(aMatch,-1,sizeof(aMatch));
    memset(bMatch,-1,sizeof(bMatch));
    for(int i=0;i<N;i++)
    {
        double x,y;
        cin>>x>>y;
        gopher.push_back({x,y});
    }
    for(int i=0;i<M;i++)
    {
        double x,y;
        cin>>x>>y;
        hole.push_back({x,y});
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(getDist(gopher[i],hole[j])/(double)V<=(double)S)adj[i].push_back(j);

    int cnt=0;
    for(int i=0;i<N;i++)
    {
        memset(visited,0,sizeof(visited));
        cnt+=dfs(i);
    }
    cout<<N-cnt<<"\n";
    }
}
