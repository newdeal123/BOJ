#include <bits/stdc++.h>
using namespace std;
const int MAX_N=100+2;
int N,M,aMatch[MAX_N*MAX_N],bMatch[MAX_N*MAX_N],board[MAX_N][MAX_N]={0,},aBoard[MAX_N][MAX_N],bBoard[MAX_N][MAX_N];
vector<int>adj[MAX_N*MAX_N];
bool visited[MAX_N*MAX_N];

bool dfs(int now)
{
    if(visited[now]) return false;
    visited[now]=true;

    for(auto next:adj[now])
    {
        if(bMatch[next]==-1 || dfs(bMatch[next]))
        {
            bMatch[next]=now;
            aMatch[now]=next;
            return true;
        }
    }
    return false;
}

void getNum()
{
    int cnt=1;
    for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
                {
                    aBoard[i][j]=cnt;
                    if(board[i][j]==2) cnt++;
                }
            cnt++;
        }
    cnt=1;
    for(int i=1;i<=M;i++)
        {
            for(int j=1;j<=N;j++)
                {
                    bBoard[j][i]=cnt;
                    if(board[j][i]==2) cnt++;
                }
            cnt++;
        }
}

int main()
{
    cin>>N>>M;
    memset(bMatch,-1,sizeof(bMatch));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>board[i][j];
    int maxN=0;
    getNum();
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(!board[i][j])
                    {
                        adj[aBoard[i][j]].push_back(bBoard[i][j]);
                        maxN=max(maxN,aBoard[i][j]);
                    }

    int sum=0;
    for(int i=1;i<=maxN;i++)
    {
        memset(visited,false,sizeof(visited));
        if(dfs(i))sum++;
    }
    cout<<sum;
}
