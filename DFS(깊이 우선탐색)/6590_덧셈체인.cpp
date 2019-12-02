#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
const int INF=987654321,MAX_N=101;
int N,minN;
int tmp[MAX_N],ans[MAX_N],dist[MAX_N*MAX_N];

void dfs(int now)
{
    if(minN<=now+dist[tmp[now]]) return;
    if(tmp[now]==N)
    {
        minN=now;
        for(int i=0;i<=now;i++)ans[i]=tmp[i];
        return;
    }

    for(int i=0;i<=now;i++)
        for(int j=i;j<=now;j++)
    {
        tmp[now+1]=tmp[i]+tmp[j];
        if(tmp[now+1]>tmp[now] && tmp[now+1]<=N)dfs(now+1);
    }
}

int main()
{
    while(true)
    {
        minN=INF;
        cin>>N;
        if(!N)break;
        for(int i=1;i<N;i++)dist[i]=1+dist[i+i];
        for(int i=N;i<=N*2;i++)dist[i]=0;
        tmp[0]=1;
        dfs(0);
        for(int i=0;i<=minN;i++)cout<<ans[i]<<" ";
        cout<<"\n";
    }
}
