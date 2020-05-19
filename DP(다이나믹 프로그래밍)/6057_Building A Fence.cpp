#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
const ll INF=98764321987654321;
const int MAX_N=2500+2;
ll cache[MAX_N];

ll f(int N)
{
    if(N==5)return 4;
    ll&ret=cache[N];
    if(ret!=-1)return ret;
    ret=0;
    if(N%2==1)return ret=f(N-2)*(N+1)/(N-5);
    else return ret=f(N-1)+(N-1)/2;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    int N;
    cin>>N;
    cout<<f(N);
}
