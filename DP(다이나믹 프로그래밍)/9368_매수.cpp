#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,c,m;
double cache[16][1<<16];
vector<pair<int,double>>v;


double f(int toNeed,int bits,int last,int money)
{
    if(toNeed==0)return 1.0;
    if(last<toNeed)return 0.0;

    double&ret=cache[toNeed][bits];
    if(ret>-0.5)return ret;
    ret=0.0;

    for(int i=0;i<n;i++)
    {
        if(bits&(1<<i)||money<v[i].first)continue;
        ret=max(ret,f(toNeed-1,bits|(1<<i),last-1,money-v[i].first)*v[i].second+
                f(toNeed,bits|(1<<i),last-1,money-v[i].first)*(1.0-v[i].second));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed;
    cout.precision(7);
    v.resize(17);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>c>>m;
        memset(cache,-1.0,sizeof(cache));
        for(int i=0;i<n;i++)
        {
            int b,p;
            cin>>b>>p;
            v[i]={b,(double)p/100.0};
        }

        cout<<f(c,0,n,m)<<"\n";
    }
}
