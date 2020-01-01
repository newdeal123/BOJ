#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<ll>v;

bool is_possible(ll mid)
{
    for(auto i:v)
        if(i>mid)return false;
        else mid=i*(mid/i);
    return true;
}

int main()
{
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++)cin>>v[i];
    ll left=0,right=LLONG_MAX-100,ret;
    while(left<=right)
    {
        ll mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    cout<<ret;
}
