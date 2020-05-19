#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
const ll INF=98764321987654321;
const int MAX_N=2000+2;
int N,L;
ll cache[MAX_N][MAX_N];
vector<int>width,height;

ll f(int idx,int last,int maxN,ll sum)
{
    if(idx==N)return maxN;
    ll&ret=cache[idx][last];
    if(ret!=-1)return ret;
    ret=INF;
    if(sum+height[idx]<=L)ret=min(ret,f(idx+1,last,max(maxN,width[idx]),sum+height[idx]));
    return ret=min(ret,f(idx+1,idx,width[idx],height[idx])+maxN);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>N>>L;
    width.resize(N+1),height.resize(N+1);
    for(int i=0;i<N;i++)
    {
        cin>>width[i]>>height[i];
    }
    cout<<f(0,0,0,0);
}
