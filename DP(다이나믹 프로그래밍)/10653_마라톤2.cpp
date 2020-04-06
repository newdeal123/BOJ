#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int INF=987654321;
int N,K,cache[501][501];
vector<pair<int,int>>v;

int getDist(pair<int,int>a,pair<int,int>b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int f(int now,int toSkip)
{
    if(now==N-1)return 0;
    int&ret=cache[now][toSkip];
    if(ret!=-1)return ret;
    ret=-INF;
    ret=f(now+1,toSkip)+getDist(v[now],v[now+1]);
    for(int next=now+2;next<N;next++)
    {
        int skip=next-now-1;
        if(toSkip>=skip)ret=min(ret,f(next,toSkip-skip)+getDist(v[now],v[next]));
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        int y,x;
        cin>>y>>x;
        v.push_back({y,x});
    }
    cout<<f(0,K);
}
