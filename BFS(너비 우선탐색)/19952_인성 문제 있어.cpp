#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
const int INF=987654321;
int N,M,O,F,startY,startX,finY,finX;
int board[101][101];
bool visited[101][101];
int goY[4]={1,-1,0,0},goX[4]={0,0,1,-1};

bool is_in_board(int y,int x){return (y>=1&&y<=N&&x>=1&&x<=M);}

bool bfs(){
    memset(visited,0,sizeof(visited));
    queue<pair<pair<int,int>,int>>q;
    visited[startY][startX]=true;
    q.push({{startY,startX},F});

    while(!q.empty()){
        int nowY=q.front().first.first,nowX=q.front().first.second;
        int nowF=q.front().second;
       // cout<<nowY<<" "<<nowX<<endl;
        q.pop();
        if(nowY==finY&&nowX==finX)return true;

        for(int i=0;i<4;i++){
            int nextY=nowY+goY[i],nextX=nowX+goX[i];
            int nextF=nowF;
            if(!is_in_board(nextY,nextX))continue;
            if(board[nowY][nowX]<board[nextY][nextX]
               &&nextF<board[nextY][nextX]-board[nowY][nowX]) continue;
            nextF-=1;
            if(nextF>=0&&!visited[nextY][nextX]){
                visited[nextY][nextX]=true;
                q.push({{nextY,nextX},nextF});
            }
        }
    }
    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>N>>M>>O>>F>>startY>>startX>>finY>>finX;
        memset(board,0,sizeof(board));
        while(O--){
            int y,x,l;
            cin>>y>>x>>l;
            board[y][x]=l;
        }
        if(bfs())cout<<"잘했어!!\n";
        else cout<<"인성 문제있어??\n";
    }
}
