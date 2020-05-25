#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=1000+2;
int N,cache[MAX_N];

int f(int n)
{
    if(n<=1)return 0;

    int&ret=cache[n];
    if(ret!=-1)return ret;
    bool visited[101]={0,};
    for(int i=n-2;i>=0;i--)
    {
        visited[f(i)^f(n-2-i)]=true;
    }
    for(int i=0;i<101;i++)if(!visited[i])return ret=i;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    cout<<(f(N)>0?1:2);
}
