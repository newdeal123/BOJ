#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int N,M,board[1025][1025];
int pSum[1025][1025];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)cin>>board[i][j];
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)pSum[i][j]=pSum[i][j-1]+board[i][j];
    }
    int Q;
    cin>>Q;
    while(Q--)
    {
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        int sum=0;
        for(int i=y1;i<=y2;i++)
        {
            sum+=pSum[i][x2]-pSum[i][x1-1];
        }
        cout<<sum<<"\n";
    }
}
