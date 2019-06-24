#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=987654321;
const ll MAX_N=(ll)1e9+2;
ll X,Y,Z;

bool is_possible(ll n)
{
    ll tmp=(long double)(Y+n)/(long double)(X+n)*(ll)(100.0);
    if(Z!=tmp) return true;
    return false;
}

int main()
{
    
    while(cin>>X>>Y)
    {
        Z=(long double)Y/(long double)X*(ll)(100.0);
        if(Z>=99)
        {
            cout<<"-1";
            continue;
        }
        ll left=0,right=LLONG_MAX-10000,ret=LLONG_MAX-1000;
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
}
