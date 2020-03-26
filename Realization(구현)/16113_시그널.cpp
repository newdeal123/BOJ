#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,board[5][20000],cnt=0;
    cin>>N;
    string s;
    cin>>s;

    for(int i=0;i<5;i++)
        for(int j=0;j<N/5;j++)
        {
            if(s[cnt++]=='#')board[i][j]=1;
            else board[i][j]=0;
        }
    for(int j=0;j<N/5;j++)
    {
        string line;
        for(int i=0;i<5;i++)line+=(to_string(board[i][j]));
        if(line=="00000")continue;
        if(line=="11111")
        {
            if(j==N/5-1){cout<<1;return 0;}
            string nextLine;
            for(int i=0;i<5;i++)nextLine+=(to_string(board[i][j+1]));
            if(nextLine=="00000"){cout<<1;j-=2;}
            else if(nextLine=="10001")cout<<0;
            else if(nextLine=="10101")
            {
                string nextLine;
                for(int i=0;i<5;i++)nextLine+=(to_string(board[i][j+2]));
                if(nextLine=="11111")cout<<8;
                else cout<<6;
            }
        }
        else if(line=="10111")cout<<2;
        else if(line=="10101")cout<<3;
        else if(line=="11100")cout<<4;
        else if(line=="11101")
        {
            string nextLine;
            for(int i=0;i<5;i++)nextLine+=(to_string(board[i][j+2]));
            if(nextLine=="10111")cout<<5;
            else cout<<9;
        }
        else if(line=="10000")cout<<7;
        j+=2;
    }
}
