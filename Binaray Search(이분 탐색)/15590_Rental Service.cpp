#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int MAX_N=(int)1e5+5;
int N,M,R;
vector<ll>cowPmilk,rental;
vector<pair<ll,ll>>store;
ll ans=0,pSum_Rental[MAX_N]={0,},pSum_Milk[MAX_N]={0,};
pair<ll,ll>pSum_Store[MAX_N];

bool compare(pair<ll,ll>a,pair<ll,ll>b)
{
   if(a.second!=b.second) return a.second>b.second;
   else a.first>b.first;
}

ll GetMilkToCoin(ll sum)
{
    if(sum>=pSum_Store[M].first)return pSum_Store[M].second;
    ll left=0,right=M,idx=0;
    while(left<=right)
    {
        ll mid=(left+right)/2;
        if(pSum_Store[mid].first<=sum)
        {
            idx=mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    ll sub=sum-pSum_Store[idx].first;
    return pSum_Store[idx].second+sub*store[idx].second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M>>R;

    //cow Per milk
    cowPmilk.resize(N);
    for(int i=0;i<N;i++)cin>>cowPmilk[i];
    sort(cowPmilk.rbegin(),cowPmilk.rend());
    for(int i=1;i<=N;i++)pSum_Milk[i]=pSum_Milk[i-1]+cowPmilk[i-1];
    for(int i=N+1;i<MAX_N;i++)pSum_Milk[i]=pSum_Milk[i-1];
    //store
    store.resize(M);
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        store[i]={a,b};
    }
    sort(store.begin(),store.end(),compare);
    pSum_Store[0]={0,0};
    for(int i=1;i<=M;i++)
    {
        pSum_Store[i]={pSum_Store[i-1].first+store[i-1].first,
        pSum_Store[i-1].second+store[i-1].first*store[i-1].second};
    }
    for(int i=M+1;i<MAX_N;i++)
        pSum_Store[i]=pSum_Store[i-1];
    //rental
    rental.resize(R);
    for(int i=0;i<R;i++)cin>>rental[i];
    sort(rental.rbegin(),rental.rend());
    for(int i=1;i<=R;i++)pSum_Rental[i]=pSum_Rental[i-1]+rental[i-1];
    for(int i=R+1;i<MAX_N;i++)pSum_Rental[i]=pSum_Rental[i-1];

    for(int i=0;i<=N;i++)
        {
           // cout<<i<<":"<<pSum_Rental[i]<<"+"<<"("<<pSum_Milk[N-i]<<")"<<GetMilkToCoin(pSum_Milk[N-i])<<endl;
            ans=max(ans,pSum_Rental[i]+GetMilkToCoin(pSum_Milk[N-i]));
        }
    cout<<ans;
}
