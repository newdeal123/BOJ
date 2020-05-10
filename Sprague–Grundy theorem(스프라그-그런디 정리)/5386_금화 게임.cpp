#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=100000+2;
int N,K,cache[MAX_N];

int f(int now)
{
    if(now==0)return 0;
    int&ret=cache[now];
    if(ret!=-1)return ret;

    bool visited[101]={0,};
    if(K==1)visited[f(now-1)]=true;
    else
    {
        for(int k=1;k<=now;k*=K)
        {
            visited[f(now-k)]=true;

        }
    }
    for(int i=0;i<101;i++)if(!visited[i]) return ret= i;
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        cin>>N>>K;
        if(K%2==1)
        {
            cout<<(N%2==1)<<"\n";
        }
        else
        {
            N=N%(K+1);
            if(N==K)cout<<K<<"\n";
            else if(N==0)cout<<0<<"\n";
            else cout<<(N%2==1)<<"\n";
        }
    }
}
