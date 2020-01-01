#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int INF=987654321;
int N,cache[21][1<<16],cnt=1;
map<string,int> mp;

struct POKEMON
{
    int y,x;
    string name;
};
POKEMON mon[21];

int f(int now,int bits)
{
    if(bits==(1<<cnt)-1)return abs(mon[now].x)+abs(mon[now].y);

    int&ret=cache[now][bits];
    if(ret!=-1)return ret;
    ret=INF;
    for(int next=1;next<=N;next++)
    {
        int type=mp[mon[next].name];
        if(now==next||bits&(1<<type))continue;
        ret=min(ret,f(next,bits|(1<<type))+abs(mon[now].y-mon[next].y)+abs(mon[now].x-mon[next].x));
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    mon[0]={0,0,""};
    for(int i=1;i<=N;i++)
    {
        int y,x;
        string s;
        cin>>y>>x>>s;
        if(mp.find(s)==mp.end())mp.insert({s,cnt++});
        mon[i]={y,x,s};
    }
    cout<<f(0,1);
}
