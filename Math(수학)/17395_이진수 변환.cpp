#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
vector<bool>bits;
vector<ll>ans;

ll vec_to_ten(vector<bool>&v)
{
    ll sum=0;
    for(int i=0;i<v.size();i++)sum+=v[i]*(ll)pow(2,v.size()-i-1);
    return sum;
}

int main()
{
    ll N,K;
    cin>>N>>K;
    if(K==1){cout<<0;return 0;}
    ans.resize(K);
    while(N>1)
    {
        if(N%2==1)bits.push_back(1);
        else bits.push_back(0);
        N/=2;
    }
    bits.push_back(1);
    reverse(bits.begin(),bits.end());

    ll sum=0;
    for(auto i:bits)sum+=i;
    if(sum<K)cout<<-1;
    else
    {
        int idx=0;
        for(int i=0;i<K-1;i++)
        {
            while(!bits[idx])idx++;
            bits[idx]=0;
            ans[i]=vec_to_ten(bits);
        }
        ans[K-1]=0;
        for(auto i:ans)cout<<i<<" ";
    }
}
