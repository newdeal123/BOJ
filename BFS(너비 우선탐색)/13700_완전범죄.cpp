#include <bits/stdc++.h>
using namespace std;
const int MAX_N=100000+2;
int N,S,D,F,B,K,board[MAX_N]={0,};

bool is_in_board(int n)
{
    if(n<1 || n>N) return false;
    return true;
}

int BFS()
{
    int visited[MAX_N]={0,};
    queue<int>q;
    visited[S]=1;
    q.push(S);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        int next=now+F;
        if(is_in_board(next) && board[next]!=1 && !visited[next])
        {
            visited[next]=visited[now]+1;
            q.push(next);
        }
        next=now-B;
        if(is_in_board(next) && board[next]!=1 && !visited[next])
        {
            visited[next]=visited[now]+1;
            q.push(next);
        }
    }
    return (visited[D]==0) ? -1:visited[D]-1;
}

int main()
{
    cin>>N>>S>>D>>F>>B>>K;
    while(K--)
    {
        int tmp;
        cin>>tmp;
        board[tmp]=1;
    }
    int ans=BFS();
    if(ans==-1) cout<<"BUG FOUND";
    else cout<<ans;
}
