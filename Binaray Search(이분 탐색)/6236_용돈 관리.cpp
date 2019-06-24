#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,M,cost[100000+2];

bool is_possible(ll mid)
{
    ll ret=0,tmpSum=0;
    for(int i=0;i<N;i++)
    {
        if(mid<cost[i]) return false;
        if(tmpSum+cost[i]<=mid) tmpSum+=cost[i];
        else
        {
            ret++;
            tmpSum=cost[i];
        }
    }
    if(ret+1<=M) return true;
    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0;i<N;i++)cin>>cost[i];
    ll left=0,right=(ll)1e9+2,ret=(ll)1e9+2;
    while(left<=right)
    {
        ll mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=min(ret,mid);
            right=mid-1;
        }
        else
            left=mid+1;
    }
    cout<<ret;
}
