#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=10000000+2;
int B,L,N,M,degree[MAX_N],indegree[MAX_N],outdegree[MAX_N],adj[MAX_N];
bool visited[MAX_N];

bool checkEuler()
{
    for(int i=0;i<N;i++)
        if(degree[i]!=0)return false;
    return true;
}

int getEuler(int now)
{
    int ret=1;
    visited[now]=true;
    for(int i=indegree[now];i<outdegree[now];i++)
    {
        int next=adj[i];
        if(!visited[next])
            ret+=getEuler(next);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>B>>L;
    M=pow(B,L);
    N=M/B;
    if(L==1)
    {
        for(int i=0;i<B;i++)cout<<i<<" ";
        return 0;
    }
    for(int i=0;i<N;i++)
        indegree[i]=i*B,outdegree[i]=i*B;
    for(int i=0;i<N;i++)
        for(int k=0;k<B;k++)
    {
        int j=((ll)i*B+k)%N;
        adj[outdegree[i]++]=j;
        degree[j]++;
        degree[i]--;
    }
    if(!checkEuler()||getEuler(0)<N){cout<<-1;return 0;}

    int cnt=0,idx=0,s[MAX_N]={0,};
    bool first=false;
    while(idx>=0)
    {
        int now=s[idx];
        if(indegree[now]==outdegree[now])
        {
            --idx;
            if(!first)cout<<now%B<<" ";
            else first=false;
        }
        else
        {
            int next=adj[indegree[now]++];
            s[++idx]=next;
        }
    }
}


