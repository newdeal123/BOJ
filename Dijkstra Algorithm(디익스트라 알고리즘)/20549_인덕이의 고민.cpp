//
//  main.cpp
//  project01
//
//  Created by 서청운 on 2021/01/20.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
const int INF=987654321;
int N,M,A,B,C;
int board[51][51];

bool is_in_board(int y,int x){return(0<=y&&y<N&&0<=x&&x<N);}

int dijkstra(int startY,int startX){
    //cost,bits,y,x
    priority_queue<pair<pair<int,int>,pair<int,int>>>pq;
    int dist[51][51][1<<4];
    for(int i=0;i<51;i++)
        for(int j=0;j<51;j++)
            for(int k=0;k<(1<<4);k++)dist[i][j][k]=INF;
    pq.push({{0,0},{startY,startX}});
    dist[startY][startX][0]=0;
    
    while(!pq.empty()){
        int nowCost=-pq.top().first.first,nowBits=pq.top().first.second;
        int nowY=pq.top().second.first,nowX=pq.top().second.second;
        pq.pop();
        //cout<<nowY<<" "<<nowX<<" "<<nowBits<<" "<<nowCost<<endl;
        if(nowCost>dist[nowY][nowX][nowBits])continue;
        if(nowBits==(1<<M)-1)return nowCost;
        vector<int>goY,goX;
        goY={1,-1,0,0},goX={0,0,1,-1};
        for(int i=0;i<4;i++){
            for(int j=1;j<51;j++){
                int nextY=nowY+goY[i]*j,nextX=nowX+goX[i]*j;
                int nextCost=nowCost+C,nextBits=nowBits;
                if(board[nextY][nextX]>=0&&!(nextBits&(1<<board[nextY][nextX]))) nextBits|=(1<<board[nextY][nextX]);
                if(!is_in_board(nextY,nextX))continue;
                if(nextCost<dist[nextY][nextX][nextBits]){
                    dist[nextY][nextX][nextBits]=nextCost;
                    pq.push({{-nextCost,nextBits},{nextY,nextX}});
                }
            }
        }
        goY={1,1,-1,-1},goX={1,-1,1,-1};
        for(int i=0;i<4;i++){
            for(int j=1;j<51;j++){
                int nextY=nowY+goY[i]*j,nextX=nowX+goX[i]*j;
                int nextCost=nowCost+B,nextBits=nowBits;
                if(!is_in_board(nextY,nextX))continue;
                if(board[nextY][nextX]>=0&&!(nextBits&(1<<board[nextY][nextX]))) nextBits|=(1<<board[nextY][nextX]);
                if(nextCost<dist[nextY][nextX][nextBits]){
                    dist[nextY][nextX][nextBits]=nextCost;
                    pq.push({{-nextCost,nextBits},{nextY,nextX}});
                }
            }
        }
        goY={2,1,-1,-2,-2,-1,1,2},goX={1,2,2,1,-1,-2,-2,-1};
        for(int i=0;i<8;i++){
            int nextBits=nowBits;
            int nextY=nowY+goY[i],nextX=nowX+goX[i];
            if(!is_in_board(nextY,nextX))continue;
            if(board[nextY][nextX]>=0&&!(nextBits&(1<<board[nextY][nextX]))) nextBits|=(1<<board[nextY][nextX]);
            int nextCost=nowCost+A;
            if(nextCost<dist[nextY][nextX][nextBits]){
               dist[nextY][nextX][nextBits]=nextCost;
               pq.push({{-nextCost,nextBits},{nextY,nextX}});
            }
        }
    }

    
    return -1;
}

int main()
{
    memset(board,-1,sizeof(board));
    cin>>N>>A>>B>>C;
    int startY,startX;
    cin>>startY>>startX>>M;
    for(int i=0;i<M;i++){
        int y,x;
        cin>>y>>x;
        board[y][x]=i;
    }
    cout<<dijkstra(startY,startX);
}
