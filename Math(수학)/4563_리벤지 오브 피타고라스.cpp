#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_N=pow(2,20)+2;

int main()
{
    while(true)
    {
        ll a,b,c,cnt=0;
        cin>>a;
        if(!a) break;
        for(ll i=1;i<a;i++)
            if((a*a)%i==0)
               {
                    b=(a*a)/i,c=i;
            ll tmp=b+c;
            if(tmp%2==0)
                {
                    tmp/=2;
                    if(b-tmp>a) cnt++;
                }
               }

        cout<<cnt<<"\n";
    }
}
