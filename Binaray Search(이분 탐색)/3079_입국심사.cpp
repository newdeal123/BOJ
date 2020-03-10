#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
    ll maxT=0;
    for(int i=0;i<N;i++)
        {
            cin >>arr[i];
            maxT=max(maxT,arr[i]);
        }
    ll left=0,right=maxT*M;
    ll ret=LLONG_MAX-1;
    while(left<=right)
    {
        ll mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    cout <<ret;
}
