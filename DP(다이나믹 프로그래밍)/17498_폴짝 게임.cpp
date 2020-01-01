#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=200000+2;
ll N,M,D,cache[MAX_N],board[MAX_N];

int naming(int y,int x)
{
    return (y-1)*M+x;
}

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M)return false;
    return true;
}

ll f(int y,int x)
{
    if(y==N)return 0;
    ll&ret=cache[naming(y,x)];
    if(ret!=-LLONG_MAX+100)return ret;
    ret=-LLONG_MAX+1000;
    for(int i=y+1;i<=y+D;i++)
        for(int j=x-D;j<=x+D;j++)
        if(is_in_board(i,j)&&abs(y-i)+abs(x-j)<=D)
            ret=max(ret,f(i,j)+board[naming(i,j)]*board[naming(y,x)]);

    return ret;
}

int main()
{
    for(int i=0;i<MAX_N;i++)cache[i]=-LLONG_MAX+100;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M>>D;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            int x;
            cin>>x;
            board[naming(i,j)]=x;
        }
    ll ret=-LLONG_MAX+1000;
    for(int j=1;j<=M;j++)ret=max(ret,f(1,j));
    cout<<ret;
}
