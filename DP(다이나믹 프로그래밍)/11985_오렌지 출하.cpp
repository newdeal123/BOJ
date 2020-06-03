#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
typedef long long ll;
const ll INF=987654321987654321;
int N,M,K;
ll cache[20002];
vector<int>orange;

ll f(int idx)
{
    if(idx==N)return 0;
    ll&ret=cache[idx];
    if(ret!=-1)return ret;
    ret=INF;
    ll minN=INF,maxN=-INF;
    for(int i=idx;i<min(idx+M,N);i++)
    {
        minN=min(minN,(ll)orange[i]);
        maxN=max(maxN,(ll)orange[i]);
        ret=min(ret,f(i+1)+K+(ll)(i-idx+1)*(maxN-minN));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>N>>M>>K;
    orange.resize(N);
    for(auto&i:orange) cin>>i;

    cout<<f(0);
}
