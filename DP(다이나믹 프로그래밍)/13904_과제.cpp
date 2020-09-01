#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int INF=987654321l,MAX_N=1000+2;
int maxN=0,N,cache[MAX_N][MAX_N];
vector<pair<int,int>>v;

int f(int days,int last)
{
    if(days>maxN)return 0;

    int&ret=cache[days][last];
    if(ret!=-1)return ret;
    ret=0;

    for(int i=last;i<N;i++)
    {
        int day=v[i].first,score=v[i].second;
        if(day<days)continue;
        ret=max(ret,f(days+1,i+1)+score);
    }
    return ret;
}


int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        maxN=max(maxN,a);
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    cout<<f(1,0);
}
