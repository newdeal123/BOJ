#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD=(int)1e9+7;
int N, cache[101][10][4][4];

int f(int idx,int last,int up,int down)
{
    if(idx==N)return 1;
    int&ret=cache[idx][last][up][down];
    if(ret!=-1)return ret%MOD;
    ret=0;
    if(idx==0)
    {
        for(int i=0;i<10;i++)
        {
            ret+=f(idx+1,i,0,0)%MOD;
            ret%=MOD;
        }
        return ret;
    }
    if(last+1!=10&&up+1!=3)ret+=f(idx+1,last+1,up+1,0)%MOD;
    if(last-1!=-1&&down+1!=3)ret+=f(idx+1,last-1,0,down+1)%MOD;

    return ret%MOD;
}

int main()
{
    cin>>N;
    memset(cache,-1,sizeof(cache));
    cout<<f(0,0,0,0);
}
