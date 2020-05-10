#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=1000;
int N,cache[MAX_N];

int db(ll n)
{
    if(n<4)return 0;
    else if(n<16)return 1;
    else if(n<82)return 2;
    else if(n<6724)return 0;
    else if(n<50626)return 3;
    else if(n<2562991876)return 1;
    else return 2;
}

int f(int now)
{
    if(now==0)return 0;
    int&ret=cache[now];
    if(ret!=-1)return ret;

    bool visited[5]={0,};
    //cout<<pow(now,0.25)<<"~"<<pow(now,0.5)<<endl;
    for(int y=0;y<now;y++)
    {
        if((double)y>=pow(now,0.25)&&(double)y<=pow(now,0.5))
            visited[f(y)]=true;
    }
    for(int i=0;i<5;i++)if(!visited[i])return ret=i;
    return ret=6;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,k=0;
    cin>>N;
    while(N--)
    {
        ll a;
        cin>>a;
        k^=db(a);
    }
    cout<<(k>0?"koosaga":"cubelover");
}
