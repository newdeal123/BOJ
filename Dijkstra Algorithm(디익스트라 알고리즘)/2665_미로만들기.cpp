#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=50+2,IMP=10000,INF=987654321;
int N,board[MAX_N][MAX_N],goY[4]={0,0,1,-1},goX[4]={1,-1,0,0};
int toOne(int y,int x)
{
    return (y-1)*N+x;
}
pair<int,int>toTwo(int n)
{
    return {n/N+1+(n%N==0?-1:0),n%N+(n%N==0?N:0)};
}
bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>N)return false;
    return true;
}

int dijkstra()
{
    priority_queue<pair<int,int>>pq;
    vector<int>dist(N*N+2,INF);
    pq.push({0,toOne(1,1)});
    dist[toOne(1,1)]=0;
    while(!pq.empty())
    {
        int nowY=toTwo(pq.top().second).first,nowX=toTwo(pq.top().second).second;
        int cost=-pq.top().first;
        pq.pop();
        if(dist[toOne(nowY,nowX)]<cost)continue;
        for(int i=0;i<4;i++)
        {
            int nextY=nowY+goY[i],nextX=nowX+goX[i];
            if(!is_in_board(nextY,nextX))continue;
            int nextDist=cost+board[nextY][nextX];
            if(nextDist<dist[toOne(nextY,nextX)])
            {
                dist[toOne(nextY,nextX)]=nextDist;
                pq.push({-nextDist,toOne(nextY,nextX)});
            }
        }
    }
    return dist[toOne(N,N)]/IMP;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=N;j++)
        {
            int tmp=s[j-1]-'0';
            if(tmp==1)board[i][j]=1;
            else board[i][j]=IMP;
        }
    }
    cout<<dijkstra();
}
