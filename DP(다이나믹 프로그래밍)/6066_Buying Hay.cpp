#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int INF=98764321;
const int MAX_N=50000+2;
int N,H,cache[MAX_N];
//sum,cost
vector<pair<int,int>>hay;
int f(int now)
{
    if(now<=0)return 0;
    int&ret=cache[now];
    if(ret!=-1)return ret;
    ret=INF;

    for(auto i:hay)
    {
        ret=min(ret,f(now-i.first)+i.second);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>H;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        hay.push_back({a,b});
    }
    cout<<f(H);
}
