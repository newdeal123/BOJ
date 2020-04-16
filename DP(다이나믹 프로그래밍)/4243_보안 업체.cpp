#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N=100+2;
const ll INF=(ll)1e17-100;
int N,M;
ll cache[MAX_N][MAX_N][2];
vector<ll>v,arr;

ll f(int left,int right,bool onLeft,int toSelect)
{
    if(toSelect==0)return 0;
    ll&ret=cache[left][right][onLeft];
    if(ret!=-1)return ret;
    ret=INF;

    if(onLeft)
    {
        if(left!=0)ret=min(ret,
        f(left-1,right,true,toSelect-1)+(ll)toSelect*abs(v[left]-v[left-1]));
        if(right!=N-1)ret=min(ret,
        f(left,right+1,false,toSelect-1)+(ll)toSelect*abs(v[left]-v[right+1]));
    }
    else
    {
        if(left!=0)ret=min(ret,
        f(left-1,right,true,toSelect-1)+(ll)toSelect*abs(v[right]-v[left-1]));
        if(right!=N-1)ret=min(ret,
        f(left,right+1,false,toSelect-1)+(ll)toSelect*abs(v[right]-v[right+1]));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N>>M;
        arr.resize(N-1);
        for(auto&i:arr)cin>>i;
        v.resize(N);
        v[M-1]=0;
        for(int i=M;i<N;i++)v[i]=v[i-1]+arr[i-1];
        for(int i=M-2;i>=0;i--)v[i]=v[i+1]-arr[i];

        //for(int i=0;i<N;i++)cout<<v[i]<<" ";
        //cout<<"\n";

        memset(cache,-1,sizeof(cache));
        cout<<f(M-1,M-1,true,N-1)<<"\n";
    }
}
