#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
const int INF=987654321;
int N;
vector<int>time;

int dijkstra()
{
    int dist[1<<15][2];
    for(int i=0;i<(1<<15);i++)
        for(int j=0;j<2;j++)dist[i][j]=INF;
    priority_queue<pair<int,pair<int,int>>>pq;
    pq.push({0,{(1<<N)-1,1}});
    dist[(1<<N)-1][1]=0;
    while(!pq.empty())
    {
        int nowBits=pq.top().second.first;
        bool leftHave=pq.top().second.second;
        int cost=-pq.top().first;
        pq.pop();
        if(dist[nowBits][leftHave]<cost)continue;
        if(leftHave)
        {
            //left 1 people
            for(int i=0;i<N;i++)
                if(nowBits&(1<<i))
            {
                int nextBits=nowBits^(1<<i);
                int nextDist=cost+time[i];
                if(dist[nextBits][false]>nextDist)
                {
                    dist[nextBits][false]=nextDist;
                    pq.push({-nextDist,{nextBits,false}});
                }
            }
            //left 2 people
            for(int i=0;i<N;i++)
                for(int j=i+1;j<N;j++)
                    if((nowBits&(1<<i))&&(nowBits&(1<<j)))
            {
                int nextBits=nowBits^(1<<i);
                nextBits^=(1<<j);
                int nextDist=cost+max(time[i],time[j]);
                if(dist[nextBits][false]>nextDist)
                {
                    dist[nextBits][false]=nextDist;
                    pq.push({-nextDist,{nextBits,false}});
                }
            }
        }
        else
        {
            //right 1 people
            for(int i=0;i<N;i++)
                if(!(nowBits&(1<<i)))
            {
                int nextBits=nowBits^(1<<i);
                int nextDist=cost+time[i];
                if(dist[nextBits][true]>nextDist)
                {
                    dist[nextBits][true]=nextDist;
                    pq.push({-nextDist,{nextBits,true}});
                }
            }
            //left 2 people
            for(int i=0;i<N;i++)
                for(int j=i+1;j<N;j++)
                    if(!(nowBits&(1<<i))&&!(nowBits&(1<<j)))
            {
                int nextBits=nowBits^(1<<i);
                nextBits^=(1<<j);
                int nextDist=cost+max(time[i],time[j]);
                if(dist[nextBits][true]>nextDist)
                {
                    dist[nextBits][true]=nextDist;
                    pq.push({-nextDist,{nextBits,true}});
                }
            }
        }
    }
    return min(dist[0][0],dist[0][1]);
}

int main()
{
    cin>>N;
    time.resize(N);
    for(auto&i:time)cin>>i;
    cout<<dijkstra();
}
