#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=100+2,MAX_M=5000+2;
int N,M,mac[MAX_N],owner[MAX_M];
vector<int> wanted[MAX_N];
bool visited[MAX_N];

bool dfs(int now)
{
    if(visited[now]) return false;
    visited[now]=true;

    for(auto thisMac:wanted[now])
    {
        if(owner[thisMac]==-1 || dfs(owner[thisMac]))
        {
            mac[now]=thisMac;
            owner[thisMac]=now;
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>N>>M;
    memset(mac,-1,sizeof(mac));
    memset(owner,-1,sizeof(owner));
    for(int i=1;i<=M;i++)
    {
        int a,b;
        cin>>a>>b;
        wanted[a].push_back(b);
    }
    int sum=0;
    for(int i=1;i<=N;i++)
    {
        memset(visited,0,sizeof(visited));
        if(dfs(i)) sum++;
    }
    cout<<sum;

}
