#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=2000000+2,INF=987654321;
bool isPrime[MAX_N];
int visited[MAX_N]={0,};

void getPrime()
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[0]=0,isPrime[1]=0;
    for(int i=2;i<MAX_N/2;i++)
    {
        if(isPrime[i])
            for(int j=i+i;j<MAX_N/2;j+=i)isPrime[j]=false;
    }
}

int change(int n,int idx)
{
    if(idx==0)return n/2;
    else if(idx==1)return n/3;
    else if(idx==2) return n+1;
    else return (n==0?n:n-1);
}

int BFS(int a,int b,int start)
{
    queue<int>q;
    q.push(start);
    visited[start]=1;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int next=change(now,i);
            if(next<=0 || next>MAX_N || visited[next])continue;
            visited[next]=visited[now]+1;
            q.push(next);
        }
    }
    int ans=INF;
    for(int i=a;i<=b;i++)if(isPrime[i]&&visited[i]!=0)ans=min(ans,visited[i]-1);
    return (ans==INF?-1:ans);
}

int main()
{
    getPrime();
    int t;
    cin>>t;
    while(t--)
    {
        memset(visited,0,sizeof(visited));
        int N,a,b,ret=INF;
        cin>>N>>a>>b;
        cout<<BFS(a,b,N)<<"\n";
    }
}
