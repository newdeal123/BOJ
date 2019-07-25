#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
int N,M,P,board[1001][1001],sum[10]={0,};
vector<int>extend;
vector<pair<int,int>>v[10];
int goY[4]={0,0,1,-1};
int goX[4]={1,-1,0,0};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M) return false;
    return true;
}

void BFS()
{
    bool flag=true;
    while(flag)
    {
        flag=false;
        for(int p=1;p<=P;p++)
        {
            queue<pair<pair<int,int>,int>> q;
            for(auto j:v[p])
                q.push(make_pair(make_pair(j.first,j.second),0));
            v[p].clear();
            while(!q.empty())
            {
                int nowY=q.front().first.first;
                int nowX=q.front().first.second;
                int cnt=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nextY=nowY+goY[i],nextX=nowX+goX[i];
                    if(is_in_board(nextY,nextX)&& board[nextY][nextX]==0 && cnt<extend[p])
                    {
                        board[nextY][nextX]=p;
                        q.push(make_pair(make_pair(nextY,nextX),cnt+1));
                        flag=true;
                        if(cnt+1==extend[p])v[p].push_back({nextY,nextX});
                    }
                }
            }

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M>>P;
    extend.resize(P+1);
    for(int i=1;i<=P;i++) cin>>extend[i];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
    {
        char c;
        cin>>c;
        if(c>='1'&&c<='9')
            {
                board[i][j]=c-'0';
                v[board[i][j]].push_back(make_pair(i,j));
            }
        else if(c=='#') board[i][j]=INF;
    }

    BFS();
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(board[i][j]>0&&board[i][j]<10) sum[board[i][j]]++;
    for(int i=1;i<=P;i++) cout<<sum[i]<<" ";
}
