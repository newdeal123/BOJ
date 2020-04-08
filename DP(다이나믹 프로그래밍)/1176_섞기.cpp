#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int N,K;
ll cache[1<<16][16];
int arr[17];

ll f(int bits,int last)
{
    if(bits==(1<<N)-1)return 1;
    ll&ret=cache[bits][last];
    if(ret!=-1)return ret;
    ret=0;

    for(int i=0;i<N;i++)
    {
        if(bits&(1<<i))continue;
        if(bits==0||abs(arr[last]-arr[i])>K)
            ret+=f(bits|(1<<i),i);
    }
    return ret;

}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>K;
    for(int i=0;i<N;i++)cin>>arr[i];
    cout<<f(0,0);
}
