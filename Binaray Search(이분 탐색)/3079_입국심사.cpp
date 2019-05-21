#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_M=(ll)1E9+1;
ll N,M,arr[100000+2];

bool is_possible(ll n)
{
    ll cnt=0;
    for(int i=0;i<N;i++)
        cnt+=n/arr[i];
    if(cnt>=M) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N>>M;
    for(int i=0;i<N;i++)
        cin >>arr[i];
    ll left=1,right=1000000000000000000LL;
    ll ret=LLONG_MAX-1;
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
    cout <<ret;
}
