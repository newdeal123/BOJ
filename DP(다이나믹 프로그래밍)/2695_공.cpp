#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int cache[50+1][1000+1];

int f(int ballN,int floor)
{
    if (ballN==1) return floor;
    if (floor==0 || floor==1)return floor;

    int&ret=cache[ballN][floor];
    if(ret!=-1)return ret;
    ret=floor;
    for (int n=1;n<=floor;++n)
        ret=min(ret,max(f(ballN-1,n-1),f(ballN,floor-n))+1);

   return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    int t;
    cin>>t;
    while(t--)
    {
      int b,m;
      cin>>b>>m;
      cout<<f(b,m)<<"\n";
    }

}
