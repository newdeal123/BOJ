#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N=1000+2,INF=(int)1e9+2;
int N,M,cache[MAX_N][MAX_N][2];
int pSum[MAX_N]={0,},leaveSum[MAX_N][MAX_N]={0,};
vector<pair<int,int>>v; //loc,cost

int f(int left,int right,bool onLeft,int selected)
{
    if(selected==N)return 0;
    int&ret=cache[left][right][onLeft];
    if(ret!=-1)return ret;
    ret=INF;

    if(onLeft)
    {
        if(left!=0)ret=min(ret,
        f(left-1,right,true,selected+1)+leaveSum[left][right]*abs(v[left].first-v[left-1].first));
        if(right!=N-1)ret=min(ret,
        f(left,right+1,false,selected+1)+leaveSum[left][right]*abs(v[left].first-v[right+1].first));
    }
    else
    {
        if(left!=0)ret=min(ret,
        f(left-1,right,true,selected+1)+leaveSum[left][right]*abs(v[right].first-v[left-1].first));
        if(right!=N-1)ret=min(ret,
        f(left,right+1,false,selected+1)+leaveSum[left][right]*abs(v[right].first-v[right+1].first));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    int startL;
    for(int i=0;i<N;i++)
    {
        int l,c;
        cin>>l>>c;
        v.push_back({l,c});
        if(i==M-1)startL=l;
    }
    sort(v.begin(),v.end());

    pSum[0]=v[0].second;
    for(int i=1;i<N;i++)pSum[i]=pSum[i-1]+v[i].second;

    memset(cache,-1,sizeof(cache));
    int start;
    for(int i=0;i<N;i++)
        if(startL==v[i].first)start=i;

    for(int i=0;i<N;i++)
        for(int j=i;j<N;j++)
    {
        leaveSum[i][j]=pSum[N-1]-pSum[j];
        if(i!=0)leaveSum[i][j]+=pSum[i-1];
    }

    cout<<f(start,start,true,1);

}
