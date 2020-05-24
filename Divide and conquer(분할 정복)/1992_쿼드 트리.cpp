#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=64+2;
int N,board[MAX_N][MAX_N];

bool allSame(pair<int,int>start,pair<int,int>fin)
{
    int type=board[start.first][start.second];

    for(int i=start.first;i<=fin.first;i++)
        for(int j=start.second;j<=fin.second;j++)
            if(board[i][j]!=type)return false;
    return true;
}

string f(pair<int,int>start,pair<int,int>fin)
{
    if(allSame(start,fin)) return to_string(board[start.first][start.second]);
    vector<int>x(2),y(2);
    int value=0,width=(fin.first-start.first+1)/2;
    for(int i=0;i<2;i++)
    {
        x[i]=value+start.first;
        y[i]=value+start.second;
        value+=width;
    }
    string ret="(";
    for(auto i:x)
            for(auto j:y)
            {
                string s=f({i,j},{i+width -1 ,j+width-1});
                ret+=s;
            }

    return ret+")";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++)
        {
            string s;
            cin>>s;
            for(int j=1;j<=N;j++)board[i][j]=s[j-1]-'0';
        }
    cout<<f({1,1},{N,N});
}
