#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int INF=987654321;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    ll sum=0,K;
    cin>>N>>M>>K;
    vector<int>cost(N);
    for(auto&i:cost)cin>>i;
    vector<pair<int,int>>v;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b&&a!=N)swap(a,b);
        v.push_back({a-1,b-1});
    }
    if(M<=1){cout<<"YES";return 0;}
    sort(v.begin(),v.end());
    int idx=0;
    for(int i=0;i<v.size();i++)
    {
        int minN=INF;
        int left=v[i].first,right=v[i].second;
        for(int j=idx;j<=left;j++)minN=min(minN,cost[j]);
        if(idx==0&&v.back().second!=0)
        {
            int end=v.back().second;
            for(int j=N-1;j>=end;j--)minN=min(minN,cost[j]);
        }
        sum+=minN;
        //cout<<"+"<<minN<<"\n";
        idx=right;
    }
    //cout<<sum<<"\n";
    if(sum<=K)cout<<"YES";
    else cout<<"NO";
}
