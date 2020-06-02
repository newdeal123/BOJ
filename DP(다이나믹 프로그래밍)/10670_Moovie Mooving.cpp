#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int INF=987654321;
int N,L,cache[1<<20],runningTime[20],ans=INF;
vector<int>startTime[20];
int getIdx(int idx,int time)
{
    int left=0,right=startTime[idx].size()-1,ret=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(startTime[idx][mid]<=time)
        {
            left=mid+1;
            ret=mid;
        }
        else right=mid-1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>N>>L;
    for(int i=0;i<N;i++)
    {
        cin>>runningTime[i];
        int cnt;
        cin>>cnt;
        startTime[i].resize(cnt);
        for(auto &j:startTime[i])cin>>j;
    }

    cache[0]=0;
    for(int bit=0;bit<(1<<N);bit++)
    {
        int now=cache[bit];
        if(now==-1)continue;
        for(int i=0;i<N;i++)
        {
            if(bit&(1<<i))continue;
            int nextBits=bit|(1<<i);
            int idx=getIdx(i,now);
            if(idx==-1)continue;

            int nextTime=startTime[i][idx]+runningTime[i];
            cache[nextBits]=max(cache[nextBits],nextTime);
        }
    }
    
    for(int bit=0;bit<(1<<N);bit++)
        if(cache[bit]>=L)
        {
            int cnt=0;
            for(int i=0;i<N;i++)if(bit&(1<<i))cnt++;
            ans=min(ans,cnt);
        }
        
    cout<<(ans==INF?-1:ans);

}
