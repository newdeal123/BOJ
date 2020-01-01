#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=(int)1e9+2,MAX_N=2000+2;
int N,A,B, cache[MAX_N*3][MAX_N];
vector<int>aV,bV;


//idx,Bcnt
int f(int idx,int cnt)
{
    if(idx==N)return 0;
    if(idx>N)return -INF;
    int&ret=cache[idx][cnt];
    if(ret!=-1)return ret;
    ret=-INF;

    if(cnt!=B) ret=max(ret,f(idx+2,cnt+1)+bV[cnt]);
    if(idx-(2*cnt)!=A) ret=max(ret,f(idx+1,cnt)+aV[idx-(2*cnt)]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>N>>A>>B;
    aV.resize(A),bV.resize(B);
    for(auto&i:aV)cin>>i;
    for(auto&i:bV)cin>>i;
    sort(aV.rbegin(),aV.rend());
    sort(bV.rbegin(),bV.rend());
    cout<<f(0,0);
}
