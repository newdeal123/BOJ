#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
const int INF=(int)1e9+2;
int N,cache[2001][2001];
vector<int>v;

int f(int idx1,int idx2)
{
    int idx=max(idx1,idx2)+1;
    if(idx>N)return 0;

    int&ret=cache[idx1][idx2];
    if(ret!=-1)return ret;
    ret=INF;
    if(idx1==0)ret=min(ret,f(idx,idx2));
    else ret=min(ret,f(idx,idx2)+abs(v[idx]-v[idx1]));

    if(idx2==0)ret=min(ret,f(idx1,idx));
    else ret=min(ret,f(idx1,idx)+abs(v[idx]-v[idx2]));

    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    v.resize(N+1);
    for(int i=1;i<=N;i++)cin>>v[i];
    cout<<f(0,0);

}
