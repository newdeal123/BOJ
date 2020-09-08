#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
int N,M,board[501][501],ans[501][501]={0,};
int goY[8]={-1,-1,-1,0,1,1,1,0},goX[8]={-1,0,1,1,1,0,-1,-1};
map<pair<int,int>,pair<int,int>>cache;

pair<int,int> f(int y,int x)
{
    if(cache.find({y,x})!=cache.end())return cache[{y,x}];
    cache.insert({{y,x},{-1,-1}});
    pair<int,int>&ret=cache[{y,x}];

    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<8;i++)
    {
        int nextY=y+goY[i],nextX=x+goX[i];
        if(nextY<1||nextY>N||nextX<1||nextX>M)continue;
        if(board[y][x]>board[nextY][nextX])v.push_back({board[nextY][nextX],{nextY,nextX}});
    }
    sort(v.begin(),v.end());
    if(v.empty())return ret={y,x};
    else return ret=f(v.front().second.first,v.front().second.second);
}

int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)cin>>board[i][j];

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            pair<int,int>ret=f(i,j);
            ans[ret.first][ret.second]++;
        }
    for(int i=1;i<=N;i++,cout<<"\n")
        for(int j=1;j<=M;j++)cout<<ans[i][j]<<" ";
}
