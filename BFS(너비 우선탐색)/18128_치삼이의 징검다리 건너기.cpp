#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=1000+2;
const int goY[8]={0,0,1,-1,1,-1,1,-1},goX[8]={1,-1,0,0,1,-1,-1,1};
int N,W,board[MAX_N][MAX_N]={0,},water[MAX_N][MAX_N]={0,},visited[MAX_N][MAX_N]={0,};
vector<pair<int,int>>waterV;

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>N) return false;
    return true;
}

void water_spread()
{
    queue<pair<int,int>>q;
    for(auto i:waterV)
    {
        q.push(i);
        water[i.first][i.second]=1;
    }
    while(!q.empty())
    {
        pair<int,int>now=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nextY=now.first+goY[i],nextX=now.second+goX[i];
            if(is_in_board(nextY,nextX)&&!water[nextY][nextX])
            {
                water[nextY][nextX]=water[now.first][now.second]+1;
                q.push({nextY,nextX});
            }
        }
    }
}

bool DFS(pair<int,int>now,int time)
{
    visited[now.first][now.second]=true;
    bool ret=false;
    for(int i=0;i<8;i++)
    {
        int nextY=now.first+goY[i],nextX=now.second+goX[i];
        if(nextY==N&&nextX==N)return true;
        if(is_in_board(nextY,nextX)&&!visited[nextY][nextX]&&board[nextY][nextX]==1&&water[nextY][nextX]<=time)
        {
            ret=max(ret,DFS({nextY,nextX},time));
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>W;
    while(W--)
    {
        int y,x;
        cin>>y>>x;
        waterV.push_back({y,x});
    }
    for(int i=1;i<=N;i++)
        {
            string s;
            cin>>s;
            for(int j=1;j<=N;j++)board[i][j]=s[j-1]-'0';
        }

    water_spread();

    //for(int i=1;i<=N;i++,cout<<"\n")
    //   for(int j=1;j<=N;j++)cout<<water[i][j]<<" ";
    int left=0,right=2*N,ret=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        memset(visited,0,sizeof(visited));
        if(DFS({1,1},mid))
        {
            ret=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    cout<<ret-1;
}
