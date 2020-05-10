#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;

ll f(ll n)
{
    switch(n & 3)
    {
    case 0: return n;
    case 1: return 1;
    case 2: return n + 1 ;
    case 3: return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    ll k=0;
    cin>>N;
    while(N--)
    {
        ll x,m;
        cin>>x>>m;
        //cout<<(f(x+m-1)^(x-1))<<endl;
        k^=f(x+m-1)^f(x-1);
    }
    cout<<(k>0?"koosaga":"cubelover");
}
