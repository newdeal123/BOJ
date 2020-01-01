#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
const int INF=987654321;
ll N,M,K;
vector<pair<ll,ll>>beer; //v,c

bool compare(pair<ll,ll>a,pair<ll,ll>b)
{
    if(a.first!=b.first)return a.first>b.first;
    else return a.second<b.second;
}

bool is_possible(ll mid)
{
    ll sum=0,cnt=N;
    for(auto i:beer)
    {
        if(i.second>mid)continue;
        sum+=i.first;
        if(--cnt==0) break;
    }
    if(sum<M||cnt!=0)return false;
    else return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M>>K;
    beer.resize(K);
    for(int i=0;i<K;i++)
    {
        ll a,b;
        cin>>a>>b;
        beer[i]={a,b};
    }
    sort(beer.begin(),beer.end(),compare);

    ll left=1,right=(ll)pow(2,31)+1,ret;
    if(!is_possible(right)){cout<<"-1";return 0;}
    while(left<=right)
    {
        ll mid=(left+right)/2;
        //cout<<mid<<"\n";
        if(is_possible(mid))
        {
            ret=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    cout<<ret;
}
