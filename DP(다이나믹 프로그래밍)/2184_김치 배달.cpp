#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N=1000+2;
const ll INF=(ll)1e17-100;
int N,M;
ll cache[MAX_N][MAX_N][2];
vector<int>v;

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
    memset(cache,-1,sizeof(cache));
    cin>>N>>M;
    v.resize(N);
    for(auto&i:v)cin>>i;
    v.push_back(M);
    N++;
    sort(v.begin(),v.end());
    int start;
    for(int i=0;i<N;i++)if(v[i]==M)start=i;

    cout<<f(start,start,true,N-1);
}
