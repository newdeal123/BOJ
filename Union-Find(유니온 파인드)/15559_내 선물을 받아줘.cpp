#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
int board[1000][1000],goY[4]={-1,1,0,0},goX[4]={0,0,-1,1};
bool visited[1000][1000];

enum{
N_,S_,W_,E_
};

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND(){;}
    UNION_FIND(int len)
    {
        n=len;
        parent.resize(n),height.resize(n,1);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    int find(int u)
    {
        if(u==parent[u]) return u;
        return find(parent[u]);
    }
    void merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v) return;
        if(height[u]>height[v]) swap(u,v);
        parent[u]=v;
        if(height[u]==height[v]) height[v]++;
    }
};

bool is_in_board(int y,int x)
{
    if(y<0||y>=N||x<0||x>=M)return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int cnt=0;
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<M;j++)
        {
            if(s[j]=='N')board[i][j]=N_;
            else if(s[j]=='W')board[i][j]=W_;
            else if(s[j]=='E')board[i][j]=E_;
            else board[i][j]=S_;
        }
    }
    
    UNION_FIND uf(N*M);

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        if(!visited[i][j])
    {
        visited[i][j]=true;
        int nowY=i+goY[board[i][j]],nowX=j+goX[board[i][j]];
        int num1=i*M+j;
        while(is_in_board(nowY,nowX))
        {
            int num2=nowY*M+nowX;
            if(visited[nowY][nowX])
            {
                if(uf.find(num1)==uf.find(num2))cnt++;
                break;
            }
            visited[nowY][nowX]=true;
            uf.merge(num1,num2);

            int nextY=nowY+goY[board[nowY][nowX]],nextX=nowX+goX[board[nowY][nowX]];
            nowY=nextY,nowX=nextX;
        }
        /*for(int i=0;i<N;i++,cout<<endl)
        for(int j=0;j<M;j++)cout<<visited[i][j]<<" ";
        cout<<endl;*/
    }
    cout<<cnt;
}
