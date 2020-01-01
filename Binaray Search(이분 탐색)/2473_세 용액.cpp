#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
vector<ll>v,output;

ll ABS(ll n)
{
    if(n>=0)return n;
    else return -n;
}
int main()
{
    output.resize(3);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++)cin>>v[i];
    sort(v.begin(),v.end());
    ll ans=LLONG_MAX-100;
    for(int i=0;i<N;i++)
    {
        int pin=i,left=i+1,right=N-1;
        while(left<right)
        {
            ll sum=v[pin]+v[left]+v[right];
            if(ABS(sum)<ans)
            {
                ans=ABS(sum);
                output={v[pin],v[left],v[right]};
            }
            if(sum<0)left++;
            else right--;
        }
    }
    for(auto i:output)cout<<i<<" ";
}
