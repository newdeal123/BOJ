#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=100000+2;
int N,cache[MAX_N];

int f(int now)
{
    if(now==0||now==2)return 0;
    int&ret=cache[now];
    if(ret!=-1)return ret;

    bool visited[101]={0,};
    for(int k=1;k<=now;k++)
    {
        if(k%2==1&&k!=now)continue;
        if(k%2==0&&k==now)continue;
        visited[f(now-k)]=true;
    }
    for(int i=0;i<101;i++)if(!visited[i]) return ret= i;
}

int db(int n)
{
    if(n%2==0)return n/2-1;
    else return (n+1)/2;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    int k=0;
    while(N--)
    {
        int tmp;
        cin>>tmp;
        k^=db(tmp);
    }
    cout<<(k>0?"koosaga":"cubelover");
}
