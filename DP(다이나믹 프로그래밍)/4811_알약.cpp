#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll cache[31][31];

ll f(int n,int k)
{
    if(n==0)return 1;
    ll&ret=cache[n][k];
    if(ret!=-1)return ret;
    ret=0;
    if(k)ret+=f(n,k-1);
    ret+=f(n-1,k+1);

    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    while(true)
    {
        int n;
        cin>>n;
        if(!n)break;
        cout<<f(n,0)<<"\n";
    }
}

