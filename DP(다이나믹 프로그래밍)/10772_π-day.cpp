#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int INF=987654321,MAX_N=250+2,MAX_LAST=125;
int cache[MAX_N][MAX_N][MAX_LAST],N,K;

int f(int idx,int remain,int last)
{
    if(idx==K)
    {
        if(remain==0)return 1;
        else return 0;
    }
    int&ret=cache[idx][remain][last];
    if(ret!=-1)return ret;
    ret=0;
    for(int next=last;next<=min(MAX_LAST-1,remain);next++)
        ret+=f(idx+1,remain-next,next);
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>K;
    cout<<f(0,N,1);
}
