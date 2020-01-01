#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX_N=50000+2,INF=987654321;
int cache[MAX_N];

int f(int n)
{
    if(n<=1)return n;
    int&ret=cache[n];
    if(ret!=-1)return ret;
    ret=INF;
    for(int i=1;i<sqrt(MAX_N);i++)
    {
        if(i*i>n)break;
        ret=min(ret,f(n-i*i)+1);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    int N;
    cin>>N;
    cout<<f(N);
}
