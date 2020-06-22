#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MOD=1e6+3;
int N,K,len,cache[51][1<<15];
vector<string>v;

int f(int idx,int bits,int same)
{
    if(idx==len)return (same==K?1:0);
    int&ret=cache[idx][bits];
    if(ret!=-1)return ret%MOD;
    ret=0;
    for(char c='a';c<='z';c++)
    {
        int nextBits=bits;
        int nextSame=same;
        for(int i=0;i<N;i++)
            if(bits&(1<<i))
        {
            if(v[i][idx]==c||v[i][idx]=='?')continue;
            nextBits^=(1<<i);
            nextSame--;
        }
        ret=(ret+f(idx+1,nextBits,nextSame))%MOD;
    }
    return ret%MOD;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>K;
    v.resize(N);
    for(auto&s:v)cin>>s;
    len=v.front().size();
    cout<<f(0,(1<<N)-1,N);
}
