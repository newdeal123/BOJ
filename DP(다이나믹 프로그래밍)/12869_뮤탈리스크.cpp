#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=987654321;
int n,cache[61][61][61];
int attack[6][3]={{1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1}};

int f(int a,int b,int c)
{
    if(a<=0&&b<=0&&c<=0)return 0;
    int&ret=cache[max(a,0)][max(b,0)][max(c,0)];
    if(ret!=-1)return ret;
    ret=INF;
    for(int i=0;i<6;i++)
        ret=min(ret,f(a-attack[i][0],b-attack[i][1],c-attack[i][2])+1);
    return ret;

}

int main()
{
    memset(cache,-1,sizeof(cache));
    int v[3]={0,};
    cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<f(v[0],v[1],v[2]);
}
