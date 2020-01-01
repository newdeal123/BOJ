#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;
const int INF=987654321;
int N,M,treeDist[501][501],visited[501][501];
int goY[4]={1,-1,0,0};
int goX[4]={0,0,1,-1};
pair<int,int> start,fin;
vector<pair<int,int>>tree;

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M)return false;
    return true;
}

void treeBfs()
{
    queue<pair<int,int>>q;
    memset(treeDist,0,sizeof(treeDist));
    for(auto i:tree)
    {
        q.push(i);
        treeDist[i.first][i.second]=1;
    }
    while(!q.empty())
    {
        pair<int,int>now=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            pair<int,int>next={now.first+goY[i],now.second+goX[i]};
            if(is_in_board(next.first,next.second)&&!treeDist[next.first][next.second])
            {
                q.push(next);
                treeDist[next.first][next.second]=treeDist[now.first][now.second]+1;
            }
        }
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)treeDist[i][j]--;
}

//mid이상인 길로만 다닐수 있는가
bool is_possible(int mid)
{
    if(treeDist[start.first][start.second]<mid)return false;

    queue<pair<int,int>>q;
    memset(visited,0,sizeof(visited));
    q.push(start);
    visited[start.first][start.second]=true;
    while(!q.empty())
    {
        pair<int,int>now=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            pair<int,int>next={now.first+goY[i],now.second+goX[i]};
            if(is_in_board(next.first,next.second)&&treeDist[next.first][next.second]>=mid&&!visited[next.first][next.second])
            {
                q.push(next);
                visited[next.first][next.second]=true;
            }
        }
    }
    if(visited[fin.first][fin.second])return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
    {
        char c;
        cin>>c;
        if(c=='+')tree.push_back({i,j});
        else if(c=='V')start={i,j};
        else if(c=='J')fin={i,j};
    }
    treeBfs();
    //for(int i=1;i<=N;i++,cout<<endl)
        //for(int j=1;j<=M;j++)cout<<treeDist[i][j]<<" ";
    int left=0,right=max(N,M),ret;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    cout<<ret;
}
