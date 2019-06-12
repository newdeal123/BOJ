#include <bits/stdc++.h>
using namespace std;
const int MAX_N=50+2;
int N,M,aMatch[MAX_N*MAX_N],bMatch[MAX_N*MAX_N],aBoard[MAX_N][MAX_N],bBoard[MAX_N][MAX_N];
vector<int>adj[MAX_N*MAX_N];
bool visited[MAX_N*MAX_N];
char board[MAX_N][MAX_N];


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

int getNum()
{
    int maxCnt=0;
    int cnt=1;
     for(int i=0;i<N;i++)
        {
            bool connected=false;
            for(int j=0;j<M;j++)
            {
                if(!connected && board[i][j]=='*') {aBoard[i][j]=cnt;connected=true;}
                else if(connected && board[i][j]=='.'){cnt++;connected=false;}
                else if(connected && board[i][j]=='*'){aBoard[i][j]=cnt;}
                if(board[i][j]=='*' && j==M-1) {cnt++;}
            }
        }
        maxCnt=max(maxCnt,cnt);
    cnt=1;
     for(int i=0;i<M;i++)
        {
            bool connected=false;
            for(int j=0;j<N;j++)
            {
                if(!connected && board[j][i]=='*') {bBoard[j][i]=cnt;connected=true;}
                else if(connected && board[j][i]=='.'){cnt++;connected=false;}
                else if(connected && board[j][i]=='*'){bBoard[j][i]=cnt;}
                if(board[j][i]=='*' && j==N-1) {cnt++;}
            }
        }
        maxCnt=max(maxCnt,cnt);
        return maxCnt;
}

int main()
{
    cin>>N>>M;
    memset(bMatch,-1,sizeof(bMatch));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>board[i][j];
    int maxN=getNum();
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(board[i][j]=='*')
            adj[aBoard[i][j]].push_back(bBoard[i][j]);
    int sum=0;
    for(int i=1;i<=maxN;i++)
    {
        memset(visited,false,sizeof(visited));
        if(dfs(i))sum++;
    }
    cout<<sum;
}
