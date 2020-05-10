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
    int&ret=cache[now];
    if(ret!=-1)return ret;
    ret=0;
    //max grundy number= 13
    bool visited[14]={0,};
    for(int k=2;k<now;k++)
    {
        //arithmetic progression, denominator->a numerator->b
        //Sn=n(2a+n-1)/2 -> a=2n+k(1-k)/2k
        int a=2*now+k*(1-k),b=2*k;
        if(a!=0&&b!=0&&a%b==0)
        {
            int bit=0;
            int first=a/b;
            for(int i=0;i<k;i++)
                bit^=f(first+i);
            visited[bit]=true;
        }
        if(a<0)break;
    }
    for(int i=0;i<14;i++)if(!visited[i])return ret=i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));

    cin>>N;
    for(int k=2;k<N;k++)
    {
        int a=2*N+k*(1-k),b=2*k;
        if(a!=0&&b!=0&&a%b==0)
        {
            int bit=0;
            int first=a/b;
            for(int i=0;i<k;i++)
                bit^=f(first+i);
            if(bit==0){cout<<k;return 0;}
        }
        if(a<0)break;
    }
    cout<<-1;
}
