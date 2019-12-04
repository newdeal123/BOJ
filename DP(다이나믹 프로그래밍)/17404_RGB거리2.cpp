#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
const int MAX_N=1000+2,INF=987654321;
int N,cost[MAX_N][3],cache[MAX_N][3][3],ans=INF;

int f(int idx,int lastC,int firstC)
{
    int&ret=cache[idx][lastC][firstC];
    if(ret!=-1)return ret;
    ret=INF;
    if(idx==N-1)
    {
        for(int i=0;i<3;i++)
            if(i!=lastC&&i!=firstC)ret=min(ret,cost[idx][i]);
        return ret;
    }

    for(int i=0;i<3;i++)
        if(i!=lastC)ret=min(ret,f(idx+1,i,firstC)+cost[idx][i]);
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<3;j++)cin>>cost[i][j];
    for(int i=0;i<3;i++) ans=min(ans,f(1,i,i)+cost[0][i]);
    cout<<ans;
}
