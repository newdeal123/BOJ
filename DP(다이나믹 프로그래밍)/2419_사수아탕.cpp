#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N=300+2,INF=(int)1e9+2;
int N,M,cache[MAX_N][MAX_N][2];
vector<int>loc;

int f(int left,int right,bool onLeft,int toSelect)
{
    if(toSelect==0)return 0;

    int&ret=cache[left][right][onLeft];
    if(ret!=-1)return ret;
    ret=INF;

    if(onLeft)
    {
        if(left!=0)ret=min(ret,f(left-1,right,true,toSelect-1)+toSelect*abs(loc[left]-loc[left-1]));
        if(right!=N-1)ret=min(ret,f(left,right+1,false,toSelect-1)+toSelect*abs(loc[left]-loc[right+1]));
    }
    else
    {
        if(left!=0)ret=min(ret,f(left-1,right,true,toSelect-1)+toSelect*abs(loc[right]-loc[left-1]));
        if(right!=N-1)ret=min(ret,f(left,right+1,false,toSelect-1)+toSelect*abs(loc[right]-loc[right+1]));
    }
    return ret;
}

int main()
{
    cin>>N>>M;
    loc.resize(N);
    N++;
    for(auto&i:loc)cin>>i;
    loc.push_back(0);
    sort(loc.begin(),loc.end());
    int start=lower_bound(loc.begin(),loc.end(),0)-loc.begin();
    int ans=0;
    //cout<<start<<"\n";
    for(int i=1;i<=N;i++)
    {
        memset(cache,-1,sizeof(cache));
        //cout<<i<<" "<<f(start,start,true,i)<<endl;
        ans=max(ans,i*M-f(start,start,true,i));
    }

    cout<<ans;

}
