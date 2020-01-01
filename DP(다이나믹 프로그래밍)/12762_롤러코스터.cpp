#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int MAX_N=1000+2,INF=987654321;
int N,cache[MAX_N][2];
vector<int>v;

int f(int idx,bool down)
{
    int&ret=cache[idx][down];
    if(ret!=-1)return ret;
    ret=0;
    for(int next=idx+1;next<v.size();next++)
    {
        if(down)
        {
            if(v[idx]>v[next])ret=max(ret,f(next,1)+1);
            else if(v[idx]<v[next])ret=max(ret,f(next,0)+1);
        }
        else if(v[idx]<v[next])ret=max(ret,f(next,0)+1);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    v.push_back(INF);
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<f(0,1);
}
