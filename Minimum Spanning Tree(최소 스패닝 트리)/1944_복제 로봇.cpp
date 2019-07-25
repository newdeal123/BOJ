#include <bits/stdc++.h>
using namespace std;
const int MAX_N=50+2;
const int INF=987654321;
int N,M,board[MAX_N][MAX_N],cache[255][255];
vector <pair<int,int>> node;
int goY[4]={1,-1,0,0};
int goX[4]={0,0,1,-1};

struct UNION_FIND
{
    int n;
    vector <int> parent,height;
    UNION_FIND(){;};
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n),height.resize(n,1);
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
        if(height[u]==height[v]) height[v]++;
    }
};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>N) return false;
    return true;
}

int BFS(int u)
{
    int ret;
    int visited[MAX_N][MAX_N]={0,};
    queue<pair<int,int>> q;
    q.push(make_pair(node[u].first,node[u].second));
    visited[node[u].first][node[u].second]=1;
    while(!q.empty())
    {
        int nowY=q.front().first,nowX=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nextY=nowY+goY[i],nextX=nowX+goX[i];
            if(is_in_board(nextY,nextX) && board[nextY][nextX]!=1 && !visited[nextY][nextX])
            {
                visited[nextY][nextX]=visited[nowY][nowX]+1;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
    for(int v=0;v<M+1;v++)
    {
        int dist=visited[node[v].first][node[v].second]-1;
        cache[u][v]= dist==-1 ?INF:dist;
    }
}

int kruskal()
{
    int ret=0;
    UNION_FIND uf(M+1);
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<M+1;i++)
        for(int j=0;j<M+1;j++)
            if(cache[i][j]!=INF) edges.push_back(make_pair(cache[i][j],make_pair(i,j)));
    sort(edges.begin(),edges.end());
    for(auto i:edges)
    {
        int dist=i.first,u=i.second.first,v=i.second.second;
        if(uf.find(u)!=uf.find(v))
        {
            uf.merge(u,v);
            ret+=dist;
        }
    }
    for(int i=1;i<M+1;i++)
        if(uf.find(0)!=uf.find(i)) return -1;
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=N;j++)
        {
            if(s[j-1]=='S'||s[j-1]=='K') node.push_back(make_pair(i,j));
            if(s[j-1]=='1') board[i][j]=1;
        }
    }
    for(int i=0;i<M+1;i++) BFS(i);

    cout<<kruskal();
}
