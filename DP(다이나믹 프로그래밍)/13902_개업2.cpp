#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int INF=98764321;
int N,M,cache[10001];
bool visited[20000+2];
vector<int>v,wok;

int f(int now)
{
    if(now==0)return 0;
    int&ret=cache[now];
    if(ret!=-1)return ret;
    ret=INF;
    for(auto i:wok)
        if(now>=i)ret=min(ret,f(now-i)+1);
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>M;
    v.resize(M);
    for(auto&i:v)cin>>i;
    for(int i=0;i<M;i++)
        for(int j=i;j<M;j++)
        {
            if(i==j)visited[v[i]]=true;
            else visited[v[i]+v[j]]=true;
        }
    for(int i=0;i<20000+2;i++)
        if(visited[i])wok.push_back(i);
    if(f(N)==INF)cout<<-1;
    else cout<<f(N);
}
