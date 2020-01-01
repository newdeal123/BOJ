#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int MAX_N=1000+2,INF=987654321;
int C,N,cache[MAX_N];
vector<pair<int,int>>v;

int f(int sum)
{
    if(sum<=0)return 0;
    int&ret=cache[sum];
    if(ret!=-1)return ret;
    ret=INF;
    for(int i=0;i<N;i++)
        ret=min(ret,f(sum-v[i].second)+v[i].first);
    return ret;
}


int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>C>>N;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    cout<<f(C);
}
