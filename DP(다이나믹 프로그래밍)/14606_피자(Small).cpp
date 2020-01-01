#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int N,cache[11];

int f(int n)
{
    if(n==1)return 0;
    int&ret=cache[n];
    if(ret!=-1)return ret;

    for(int i=1;i<n;i++)ret=max(ret,f(i)+f(n-i)+i*(n-i));
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    cout<<f(N);
}
