#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;
const int MAX_N=50+2,INF=987654321;
int N,M,K,board[MAX_N][MAX_N],tmpBoard[MAX_N][MAX_N],ans=INF;
bool hadMove[MAX_N][MAX_N];
vector<int>order;
int goY[4]={1,0,-1,0};
int goX[4]={0,1,0,-1};

struct ARR
{
    int r,c,s;
};
vector<ARR>query;

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M)return false; 
    else return true;
}

void arrMove(int y,int x)
{
    int nowY=y,nowX=x,dir=0;
    while(true)
    {
        int nextY=nowY+goY[dir],nextX=nowX+goX[dir];
        if(nextY==y&&nextX==x)break;
        if(!is_in_board(nextY,nextX)|| hadMove[nextY][nextX] ) dir++,nextY=nowY+goY[dir],nextX=nowX+goX[dir];
        swap(tmpBoard[nowY][nowX],tmpBoard[nextY][nextX]);
        hadMove[nowY][nowX]=true;
        nowY=nextY,nowX=nextX;
    }
    hadMove[nowY][nowX]=true;
}

void getAns()
{
    for(int i=1;i<=N;i++)
    {
        int sum=0;
        for(int j=1;j<=M;j++)
            sum+=tmpBoard[i][j];
        ans=min(ans,sum);
    }
}

int main()
{
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)cin>>board[i][j];
    for(int i=0;i<K;i++)
    {
        int R,C,S;
        cin>>R>>C>>S;
        query.push_back({R,C,S});
    }
    for(int i=0;i<K;i++)order.push_back(i);
    do
    {
        memcpy(tmpBoard,board,sizeof(board));
        for(int i=0;i<order.size();i++)
        {
            int y=query[order[i]].r,x=query[order[i]].c,len=query[order[i]].s;

            memset(hadMove,1,sizeof(hadMove));
            for(int i=y-len;i<=y+len;i++)
                for(int j=x-len;j<=x+len;j++)hadMove[i][j]=false;

            for(int i=len;i>0;i--) arrMove(y-i,x-i);
        }
       getAns();
    }while(next_permutation(order.begin(),order.end()));

    cout<<ans;
}
