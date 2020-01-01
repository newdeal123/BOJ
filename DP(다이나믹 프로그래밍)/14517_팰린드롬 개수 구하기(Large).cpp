#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int MAX_N=1000+2,INF=987654321,MOD=10007;
int cache[MAX_N][MAX_N];
string s;


int f(int left,int right)
{
    if(left==right)return 1;
    if(left>right)return 0;

    int&ret=cache[left][right];
    if(ret!=-1)return ret%MOD;
    ret=(f(left+1,right)+f(left,right-1)-f(left+1,right-1)+MOD)%MOD;
    if(s[left]==s[right])ret+=f(left+1,right-1)+1%MOD;
    return ret%MOD;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>s;
    cout<<f(0,s.size()-1);
}
