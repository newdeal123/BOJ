#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MOD=10000;
int N,K,arr[101]={0,},cache[101][4][4];

int f(int day,int p1,int p2)
{
    if(day==N+1) return 1;
    int&ret=cache[day][p1][p2];
    if(ret!=-1) return ret;
    ret=0;
    if(arr[day]!=0)
    {
        if(arr[day]==p1 && arr[day]==p2) return 0;
        else  return ret=f(day+1,p2,arr[day])%MOD;
    }
    for(int i=1;i<=3;i++)
    {
        if(p1==i && p2==i) continue;
        ret+=f(day+1,p2,i)%MOD;
        ret%=MOD;
    }
    return ret%MOD;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>K;
    while(K--)
    {
        int d,type;
        cin>>d>>type;
        arr[d]=type;
    }
    cout<<f(1,0,0);
}
