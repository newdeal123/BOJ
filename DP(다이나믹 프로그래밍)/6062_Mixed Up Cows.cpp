#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int N,K;
ll cache[1<<16][17];
vector<int>serialN;

ll f(int bits,int last)
{
    if(bits==(1<<N)-1)return 1;
    ll&ret=cache[bits][last];
    if(ret!=-1)return ret;
    ret=0;

    for(int i=0;i<N;i++)
        if(!(bits&(1<<i))&&(bits==0||abs(serialN[last]-serialN[i])>K))ret+=f(bits|(1<<i),i);
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>K;
    serialN.resize(N);
    for(auto&i:serialN)cin>>i;
    cout<<f(0,0);
}
