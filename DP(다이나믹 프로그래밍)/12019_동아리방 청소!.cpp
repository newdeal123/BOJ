#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int N,M,cache[101][2001][11];
int arr[101];

int f(int idx,int dirty,int chance)
{
    if(idx==N) return 0;
    int&ret=cache[idx][dirty][chance];
    if(ret!=-1) return ret;
    ret=INF;
    if(chance) ret=min(ret,f(idx+1,0,chance-1)+dirty*arr[idx]);
    ret=min(ret,f(idx+1,arr[idx]+dirty,chance)+dirty*arr[idx]);
    return ret;
}

void output(int idx,int dirty,int chance)
{
    if(idx==N) return;

    int ret1=INF,ret2;
    if(chance)ret1=f(idx+1,0,chance-1)+dirty*arr[idx];
    ret2=f(idx+1,arr[idx]+dirty,chance)+dirty*arr[idx];
    if(ret1<=ret2)
    {
        cout<<idx+1<<" ";
        return output(idx+1,0,chance-1);
    }
    else return output(idx+1,arr[idx]+dirty,chance);
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>arr[i];
    cout<<f(0,0,M)<<"\n";
    output(0,0,M);
}
