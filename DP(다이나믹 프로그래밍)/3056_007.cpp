#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int N,arr[20][20];
double cache[1<<20];

double f(int idx,int bits)
{
    if(idx==N)
        return 1.0;

    double&ret=cache[bits];
    if(ret>-0.5)
        return ret;
    ret=0.0;
    for(int i=0;i<N;i++)
    {
        if(bits&(1<<i)) continue;
        ret=max(ret,f(idx+1,bits|(1<<i))*((double)arr[idx][i]/100.0));
    }
    return ret;
}

int main()
{
    memset(cache,-1.0,sizeof(cache));
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        cin>>arr[i][j];
    cout.precision(6);
    cout<<fixed;
    cout<<f(0,0)*100;
}
