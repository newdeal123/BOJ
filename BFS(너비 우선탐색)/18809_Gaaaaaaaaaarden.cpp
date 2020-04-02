#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int N,M,G,R,ans=0;
int board[52][52],tmp[52][52],goY[4]={0,0,1,-1},goX[4]={1,-1,0,0};

enum{
WALL,LAND,CLAND,SEED,GSEED,RSEED
};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M)return false;
    return true;
}

int bfs()
{
    queue<pair<int,int>>q;
    int visited[52][52]={0,},ret=0;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        if(board[i][j]==RSEED||board[i][j]==GSEED)
    {
        q.push({i,j});
        visited[i][j]=1;
    }

    while(!q.empty())
    {
        pair<int,int>now=q.front();
        q.pop();
        if(board[now.first][now.second]==WALL)continue;
        for(int i=0;i<4;i++)
        {
            pair<int,int>next=now;
            next.first+=goY[i],next.second+=goX[i];
            if(!is_in_board(next.first,next.second)||board[next.first][next.second]==WALL) continue;

            if(!visited[next.first][next.second])
            {
                q.push(next);
                visited[next.first][next.second]=visited[now.first][now.second]+1;
                board[next.first][next.second]=board[now.first][now.second];
            }
            else if(visited[next.first][next.second]==visited[now.first][now.second]+1)
            {
                if((board[next.first][next.second]==GSEED&&board[now.first][now.second]==RSEED
                    )||(board[next.first][next.second]==RSEED&&board[now.first][now.second]==GSEED))
                    {
                        ret+=1;
                        board[next.first][next.second]=WALL;
                    }
            }
        }

    }

    return ret;
}

void makeSeed()
{
	vector<pair<int,int>>canSeed;
	vector<int>order;
	for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(board[i][j]==CLAND)canSeed.push_back({i,j});

	for(int i=0;i<canSeed.size()-(G+R);i++)order.push_back(LAND);
	for(int i=0;i<G;i++)order.push_back(GSEED);
	for(int i=0;i<R;i++)order.push_back(RSEED);

	do{
        for(int i=0;i<order.size();i++)
            board[canSeed[i].first][canSeed[i].second]=order[i];

        int flowerCnt=bfs();
        ans=max(flowerCnt,ans);
        
        memcpy(board,tmp,sizeof(board));

	}while(next_permutation(order.begin(),order.end()));

}

int main()
{
    
    cin>>N>>M>>G>>R;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)cin>>board[i][j];
    memcpy(tmp,board,sizeof(tmp));
    makeSeed();
    cout<<ans;
}
