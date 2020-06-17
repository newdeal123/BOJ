#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
const int INF=987654321;
vector<int>bits;
int N;

int f(int idx,int upBits,int nowBits)
{
    if(idx==N)return (upBits==0?0:INF);
    int downBits=bits[idx+1];
    int diff=0;
    for(int i=0;i<N;i++)
        if(upBits&(1<<i))
    {
        diff++;
        if(i>0)nowBits^=(1<<(i-1));
        if(i<N-1)nowBits^=(1<<(i+1));
        nowBits^=(1<<i);
        downBits^=(1<<i);
    }
    return f(idx+1,nowBits,downBits)+diff;
}

int main()
{
    cin>>N;
    bits.resize(N+1);
    for(int i=0;i<N;i++)
    {
        int bit=0;
        for(int j=0;j<N;j++)
        {
            int tmp;
            cin>>tmp;
            if(tmp)bit|=(1<<j);
        }
        bits[i]=bit;
    }
    int ans=INF;
    for(int i=0;i<(1<<N);i++)
    {
        int upBits=bits[0];
        int downBits=bits[1];
        int diff=0;
        for(int j=0;j<N;j++)
            if(i&(1<<j))
        {
            diff++;
            if(j>0)upBits^=(1<<(j-1));
            if(j<N-1)upBits^=(1<<(j+1));
            upBits^=(1<<j);
            downBits^=(1<<j);
        }
        //cout<<i<<" "<<upBits<<" "<<downBits<<endl;
        ans=min(ans,f(1,upBits,downBits)+diff);
    }
    cout<<(ans==INF?-1:ans);
}
