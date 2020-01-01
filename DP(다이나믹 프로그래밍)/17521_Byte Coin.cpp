#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX_N=100000+2,INF=987654321;
int N,W,price[16];

ll f(int idx,ll coin,ll money)
{
    if(idx==N)return money;
    ll ret=0;
    return ret=max(f(idx+1,coin,money),max(f(idx+1,0,money+coin*price[idx]),f(idx+1,coin+money/price[idx],money-(money/price[idx])*price[idx])));
}

int main()
{
    cin>>N>>W;
    for(int i=0;i<N;i++)cin>>price[i];
    cout<<f(0,0,W);
}
