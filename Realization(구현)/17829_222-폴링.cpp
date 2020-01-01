#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int N,board[1025][1025];

int pooling(pair<int,int>start,pair<int,int>fin)
{
    if(abs(start.first-fin.first)==1)
    {
        vector<int>v;
        v.push_back(board[start.first][start.second]);
        v.push_back(board[start.first][start.second+1]);
        v.push_back(board[fin.first][fin.second-1]);
        v.push_back(board[fin.first][fin.second]);
        sort(v.begin(),v.end());
       // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
        return v[2];
    }
    vector<int>v;
    int midY=(start.first+fin.first)/2,midX=(start.second+fin.second)/2;
    v.push_back(pooling(start,{midY,midX}));
    v.push_back(pooling({start.first,midX+1},{midY,fin.second}));
    v.push_back(pooling({midY+1,start.second},{fin.first,midX}));
    v.push_back(pooling({midY+1,midX+1},fin));
    sort(v.begin(),v.end());
    //cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
    return v[2];
}

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)cin>>board[i][j];
    cout<<pooling({1,1},{N,N});
}
