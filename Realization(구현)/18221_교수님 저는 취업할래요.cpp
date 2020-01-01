#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int N,board[1001][1001];
pair<int,int>p,s;

bool getAns()
{
    if(5.0>sqrt((p.first-s.first)*(p.first-s.first)+(p.second-s.second)*(p.second-s.second))) return false;
    int cnt=0;
    for(int i=min(p.first,s.first);i<=max(p.first,s.first);i++)
        for(int j=min(p.second,s.second);j<=max(p.second,s.second);j++)
        if(board[i][j]==1)cnt++;
    if(cnt>=3)return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
    {
        cin>>board[i][j];
        if(board[i][j]==2)s={i,j};
        else if(board[i][j]==5)p={i,j};
    }
    cout<<getAns();
}
