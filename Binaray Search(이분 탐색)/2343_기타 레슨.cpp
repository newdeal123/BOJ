#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,M,len[100000+2];

bool is_possible(ll mid)
{
    ll ret=0,tmpSum=0;
    for(int i=0;i<N;i++)
    {
        if(mid<len[i]) return false;
        if(tmpSum+len[i]<=mid) tmpSum+=len[i];
        else
        {
            ret++;
            tmpSum=len[i];
        }
    }
    if(ret+1<=M) return true;
    return false;
}

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)cin>>len[i];
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
