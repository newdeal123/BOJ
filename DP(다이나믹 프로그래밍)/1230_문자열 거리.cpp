#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
const int INF=987654321,MAX_N=1000+2;
char s1[MAX_N],s2[MAX_N];
int N,M,cache[MAX_N][MAX_N][2];

int f(int idx1,int idx2,bool add)
{
    if(idx1==N)
    {
        if(idx2==M)return 0;
        else return 1;
    }
    if(idx2==M)return INF;
    int&ret=cache[idx1][idx2][add];
    if(ret!=-1)return ret;
    ret=min(INF,f(idx1,idx2+1,1)+!add);
    if(s1[idx1]==s2[idx2])ret=min(ret,f(idx1+1,idx2+1,0));
    return ret;

}

int main()
{
    memset(cache,-1,sizeof(cache));
    gets(s1);
    gets(s2);
    for(N=0;s1[N]!=NULL;)N++;
    for(M=0;s2[M]!=NULL;)M++;
    //cout<<N<<","<<M<<endl;;
    if(f(0,0,0)==INF)cout<<"-1";
    else cout<<f(0,0,0);
}
