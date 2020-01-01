#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
int N,T,cache[101][10000+2];
vector<pair<int,int>>v;

int f(int idx,int time)
{
    if(idx==N||time==0)return 0;

    int&ret=cache[idx][time];
    if(ret!=-1)return ret;
    ret=0;

    if(time<v[idx].first)return ret=f(idx+1,time);
    else return ret=max(f(idx+1,time),f(idx+1,time-v[idx].first)+v[idx].second);
}

int main()
{
    cin>>N>>T;
    memset(cache,-1,sizeof(cache));
    v.resize(N);
    for(int i=0;i<N;i++)
    {
        int k,s;
        cin>>k>>s;
        v[i]={k,s};
    }
    cout<<f(0,T);
}
