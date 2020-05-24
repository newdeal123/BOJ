#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=pow(3,7)+2;
int N,board[MAX_N][MAX_N],cnt[3]={0,};

bool allSame(pair<int,int>start,pair<int,int>fin)
{
    int type=board[start.first][start.second];

    for(int i=start.first;i<=fin.first;i++)
        for(int j=start.second;j<=fin.second;j++)
            if(board[i][j]!=type)return false;
    return true;
}
void f(pair<int,int>start,pair<int,int>fin)
{
    if(allSame(start,fin))
    {
        cnt[board[start.first][start.second]+1]++;
        return ;
    }
    vector<int>x(3),y(3);
    int value=0,width=(fin.first-start.first+1)/3;
    for(int i=0;i<3;i++)
    {
        x[i]=value+start.first;
        y[i]=value+start.second;
        value+=width;
    }
    for(auto i:x)
            for(auto j:y) f({i,j},{i+width -1 ,j+width-1});
        
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)cin>>board[i][j];
    f({1,1},{N,N});
    for(int i=0;i<3;i++)cout<<cnt[i]<<"\n";
}
