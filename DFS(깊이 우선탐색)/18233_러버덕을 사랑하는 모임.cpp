#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int N,P,E;
bool flag[21],success;
vector<pair<int,int>>v;

void getAns()
{
    int remain=E;
    for(int i=0;i<N;i++)if(flag[i])remain-=v[i].first;
    for(int i=0;i<N;i++)
        if(flag[i])
    {
        cout<<min(remain+v[i].first,v[i].second)<<" ";
        remain=max(remain-(v[i].second-v[i].first),0);
    }
    else cout<<"0 ";
}

void search(int idx,int cnt)
{
    if(cnt==0)
    {
        //for(int i=0;i<N;i++)cout<<flag[i]<<" ";
        //cout<<endl;
        int minSum=0,maxSum=0;
        for(int i=0;i<N;i++)
            if(flag[i])minSum+=v[i].first,maxSum+=v[i].second;
        if(minSum<=E&&E<=maxSum)
        {
            getAns();
            success=true;
        }
        return ;
    }
    if(success)return ;

    for(int i=idx;i<N;i++)
    {
        if(flag[i])continue;
        flag[i]=true;
        search(i,cnt-1);
        flag[i]=false;
        if(success) return ;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>P>>E;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    memset(flag,0,sizeof(flag));
    success=false;
    search(0,P);
    if(!success)cout<<"-1";
}
