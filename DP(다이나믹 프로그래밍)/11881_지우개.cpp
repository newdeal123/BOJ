#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD=(int)1e9+7;
int N,cnt[100000+2]={0,},cache[100000+2][3];

int f(int value,int select)
{
    if(select==3)return 1;
    if(value==100001)return 0;
    int&ret=cache[value][select];
    if(ret!=-1)return ret%MOD;
    ll tmp=f(value+1,select)%MOD;
    if(cnt[value])tmp+=(ll)f(value+1,select+1)*value*cnt[value]%MOD;
    ret=tmp%MOD;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        cnt[tmp]++;
    }
    cout<<f(1,0);
}
