#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int INF=987654321,MAX_N=100+2,MOD=10007;
int N,cache[MAX_N][MAX_N][MAX_N],goA[4]={0,0,1,1},goB[4]={0,1,0,1};

int f(int loc,int a,int b)
{
    if(loc==N-1)return 1;
    int&ret=cache[loc][a][b];
    if(ret!=-1)return ret%MOD;
    ret=0;
    for(int i=0;i<4;i++)
    {
        int nextA=a+goA[i],nextB=b+goB[i];
        if(nextA!=nextB)ret+=f(loc+1,nextA,nextB)%MOD;
        ret%=MOD;
    }
    return ret;

}

int main()
{
    cin>>N;
    memset(cache,-1,sizeof(cache));
    cout<<f(0,0,0)%MOD;
}
