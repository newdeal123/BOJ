#include<bits/stdc++.h>
using namespace std;
int N,M;
vector<pair<int,int>>adj[101];
vector<int>ans;
bool visited[101];
bool root[101]={0,};

void dfs(int now)
{
    if(visited[now]) return ;
    visited[now]=true;
    for(auto next:adj[now])
        dfs(next.first);
    ans.push_back(now);

}

vector <int> dfsAll()
{
    memset(visited,false,sizeof(visited));
    ans.resize(N+1);
    for(int i=1;i<=N;i++) if(!visited[i])dfs(i);
    reverse(ans.begin(),ans.end());
    vector<vector<int>> v(N+1);
    for(int i=0;i<=N;i++)
        {
            v[i].resize(N+1);
            for(auto j:v[i]) j=0;
        }

    for(int i=1;i<=N;i++)
        if(root[i]) v[i][i]=1;

    for(int i=0;i<N;i++)
    {
        int now=ans[i];
        for(int j=i+1;j<N;j++)
                for(auto next:adj[now])
                    if(next.first==ans[j])
                    {
                        for(int k=1;k<=N;k++)
                            v[next.first][k]+=v[now][k]*next.second;
                    }
    }

    return v[N];
}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    ans.resize(N+1);
    while(M--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[b].push_back(make_pair(a,c));
    }
    memset(root,true,sizeof(root));
    for(int i=1;i<=N;i++)
        for(auto j:adj[i])
            root[j.first]=false;

    vector<int>v=dfsAll();
    for(int i=1;i<=N;i++)
        if(v[i]) cout<<i<<" "<<v[i]<<"\n";
}
