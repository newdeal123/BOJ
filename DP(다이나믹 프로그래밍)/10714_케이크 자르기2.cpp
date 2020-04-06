#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int N;
ll cache[2001][2001];
vector<int>v;

ll f(int left,int right,bool myTurn)
{
    if(left==right)return (myTurn?v[left]:0);
    if(!myTurn)
    {
        if(v[left]>v[right])return f((left+1==N+1?1:left+1),right,true);
        else return f(left,(right-1==0?N:right-1),true);
    }
    ll&ret=cache[left][right];
    if(ret!=-1)return ret;

    return ret=max(f((left+1==N+1?1:left+1),right,false)+v[left],f(left,(right-1==0?N:right-1),false)+v[right]);
}


int main()
{
    memset(cache,-1,sizeof(cache));
    ll ret=0;
    cin>>N;
    v.resize(N+1);
    for(int i=1;i<=N;i++)cin>>v[i];
    for(int i=1;i<=N;i++)ret=max(ret,f((i+1==N+1?1:i+1),(i-1==0?N:i-1),false)+v[i]);
    cout<<ret;
}
