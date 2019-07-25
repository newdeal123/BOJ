#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1000+2;
int N;
bool board[MAX_N][MAX_N]={0,}, visited[MAX_N][MAX_N]={0,};
vector<pair<int,int>>ans;//area,perimeter
int goY[4]={0,0,1,-1};
int goX[4]={1,-1,0,0};

bool compare(pair<int,int>a,pair<int,int>b)
{
    if(a.first!=b.first) return a.first>b.first;
    else return a.second<b.second;
}

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>N) return false;
    return true;
}

int getPer(int y,int x)
{
    int cnt=0;
    for(int i=0;i<4;i++)
    {
        int nextY=y+goY[i],nextX=x+goX[i];
        if(!is_in_board(nextY,nextX)|| board[nextY][nextX]==1) cnt++;
    }
    return cnt;
}

void BFS(int y,int x)
{
    visited[y][x]=true;
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    int areaCnt=1,perCnt=getPer(y,x);
    while(!q.empty())
    {
        int nowY=q.front().first,nowX=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nextY=nowY+goY[i],nextX=nowX+goX[i];
            if(!is_in_board(nextY,nextX)|| board[nextY][nextX]==1 || visited[nextY][nextX]) continue;
            visited[nextY][nextX]=true;
            q.push(make_pair(nextY,nextX));
            areaCnt++;
            perCnt+=getPer(nextY,nextX);
        }
    }

    ans.push_back(make_pair(areaCnt,perCnt));

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            {
                char c;
                cin>>c;
                if(c=='.')board[i][j]=1;
            }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(!visited[i][j] && board[i][j]==0)
            BFS(i,j);
    sort(ans.begin(),ans.end(),compare);
    cout<<ans.front().first<<" "<<ans.front().second;
}
