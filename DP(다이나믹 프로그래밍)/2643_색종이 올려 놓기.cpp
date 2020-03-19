#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int N,cache[100+2][2];
vector<pair<int,int>>v;

int f(int idx,bool turned)
{
    int&ret=cache[idx][turned];
    if(ret!=-1)return ret;
    ret=0;
    int y,x;
    if(turned)y=v[idx].second,x=v[idx].first;
    else y=v[idx].first,x=v[idx].second;
    for(int i=0;i<N;i++)
    {
        if(i==idx)continue;
        if(v[i].first<=y&&v[i].second<=x)ret=max(ret,f(i,false)+1);
        if(v[i].second<=y&&v[i].first<=x)ret=max(ret,f(i,true)+1);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    int ret=0;
    for(int i=0;i<N;i++)ret=max(ret,max(f(i,true)+1,f(i,false)+1));
    cout<<ret;
}
