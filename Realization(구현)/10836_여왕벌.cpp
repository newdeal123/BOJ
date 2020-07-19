#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int board[701][701],grow[701]={0,};
int N,M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)board[i][j]=1;

    int order[1400]={0,};
    while(M--)
    {
        int cnt=0;
        for(int i=0;i<3;i++)
        {
            int tmp;
            cin>>tmp;
            while(tmp--)
            {
                order[cnt++]+=i;
            }
        }
    }
        int cnt=0;
        for(int j=N;j>=1;j--)
            board[j][1]+=order[cnt++];

        for(int i=2;i<=N;i++)
        {
            for(int j=1;j<=N;j++)board[j][i]+=order[cnt];
            cnt++;
        }


    for(int i=1;i<=N;i++,cout<<"\n")
        for(int j=1;j<=N;j++)cout<<board[i][j]<<" ";
}
