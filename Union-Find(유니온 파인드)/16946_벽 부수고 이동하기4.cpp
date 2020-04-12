#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N=1000+5;
int N,M;
bool board[MAX_N][MAX_N],visited[MAX_N][MAX_N];
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

struct UNION_FIND
{
    int n;
    vector<int>parent,height,Sum;
    UNION_FIND(){;}
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n),height.resize(n,1),Sum.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
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
        Sum[v]+=Sum[u];
        if(height[u]==height[v]) height[v]++;
    }
    int getSum(int u)
    {
        return Sum[find(u)];
    }
};
UNION_FIND uf(1000000);

bool is_in_board(pair<int,int>a)
{
    if(a.first<0||a.first>=N||a.second<0||a.second>=M)return false;
    return true;
}

void bfs(int y,int x)
{
    queue<pair<int,int>>q;
    visited[y][x]=true;
    q.push({y,x});

    while(!q.empty())
    {
        pair<int,int>now=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            pair<int,int>next=now;
            next.first+=goY[i],next.second+=goX[i];
            if(is_in_board(next)&&!visited[next.first][next.second]&&board[next.first][next.second]==0)
            {
                visited[next.first][next.second]=true;
                q.push(next);
                uf.merge((now.first*M+now.second),(next.first*M+next.second));
            }
        }
    }
}

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<M;j++)
            board[i][j]=s[j]-'0';
    }

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        if(!visited[i][j]&&board[i][j]==0) bfs(i,j);

    for(int i=0;i<N;i++,cout<<"\n")
        for(int j=0;j<M;j++)
    {
        if(board[i][j]==1)
        {
            int sum=1;
            vector<int>did;
            for(int k=0;k<4;k++)
            {
                int nextY=i+goY[k],nextX=j+goX[k];
                if(!is_in_board({nextY,nextX})||board[nextY][nextX]==1)
                    continue;

                bool found=false;
                for(auto d:did)if(uf.find(nextY*M+nextX)==d)found=true;
                if(found)continue;
                did.push_back(uf.find(nextY*M+nextX));
                sum+=uf.getSum((nextY*M+nextX));
            }
            cout<<sum%10;
        }
        else cout<<0;
    }

}
