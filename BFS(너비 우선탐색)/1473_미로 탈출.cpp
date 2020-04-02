#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int INF=987654321;
int N,M,goY[4]={0,0,1,-1},goX[4]={1,-1,0,0};
string board[7];
int visited[7][7][1<<7][1<<7]={0,};

struct NODE
{
    int y,x,bitsY,bitsX;
};

void changeRoom(NODE node,char& c)
{
    if(node.bitsY&(1<<node.y))
    {
        if(c=='C')c='D';
        else if(c=='D')c='C';
    }
    if(node.bitsX&(1<<node.x))
    {
        if(c=='C')c='D';
        else if(c=='D')c='C';
    }
}

bool is_in_board(int y,int x)
{
    if(y<0||y>=N||x<0||x>=M)return false;
    return true;
}

bool can_go(char now,char next,int state)
{
    if(now=='B'||next=='B')return false;
    //go right,left
    if(state==0||state==1)
    {
        if(now=='C'||next=='C')return false;
    }
    //go up,down
    else
    {
        if(now=='D'||next=='D')return false;
    }
    return true;
}

int bfs()
{
    queue<NODE>q;
    q.push({0,0,0,0});
    visited[0][0][0][0]=1;
    while(!q.empty())
    {
        NODE now=q.front();
        q.pop();
        char nowRoom=board[now.y][now.x];
        changeRoom(now,nowRoom);
        //cout<<now.y<<" "<<now.x<<endl;
        if(now.y==N-1&&now.x==M-1)return visited[now.y][now.x][now.bitsY][now.bitsX]-1;
        for(int i=0;i<4;i++)
        {
            NODE next={now.y+goY[i],now.x+goX[i],now.bitsY,now.bitsX};
            if(!is_in_board(next.y,next.x)||visited[next.y][next.x][next.bitsY][next.bitsX])continue;
            char nextRoom=board[next.y][next.x];
            changeRoom(next,nextRoom);
            if(!can_go(nowRoom,nextRoom,i))continue;

            q.push(next);
            visited[next.y][next.x][next.bitsY][next.bitsX]=visited[now.y][now.x][now.bitsY][now.bitsX]+1;
        }

        {
            NODE next={now.y,now.x,now.bitsY^(1<<now.y),now.bitsX^(1<<now.x)};
            if(!visited[next.y][next.x][next.bitsY][next.bitsX])
            {
                q.push(next);
                visited[next.y][next.x][next.bitsY][next.bitsX]=visited[now.y][now.x][now.bitsY][now.bitsX]+1;
            }
        }
    }
    return -1;
}

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)cin>>board[i];
    cout<<bfs();
}
