#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

ll GCD(ll a,ll b)
{
    if(!b)return a;
    return GCD(b,a%b);
}
ll LCM(ll a,ll b)
{
    return a*b/GCD(a,b);
}


int main()
{
    int N;
    cin>>N;
    vector<ll>v(N);
    for(auto&i:v)cin>>i;
    if(N==1){cout<<v[0]<<"/"<<1;return 0;}
    ll m=LCM(v[0],v[1]),sum=0;
    for(int i=2;i<N;i++)m=LCM(m,v[i]);
    for(int i=0;i<N;i++)sum+=m/v[i];
    ll gcd=GCD(m,sum);
    m/=gcd;sum/=gcd;
    cout<<m<<"/"<<sum;

}
