#include<bits/stdc++.h>
using namespace std;
int N,K;
vector<int>adj[1001],ans,buildTime;
bool visited[1001];

void dfs(int now)
{
    if(visited[now]) return ;
    visited[now]=true;
    for(auto next:adj[now])
        dfs(next);
    ans.push_back(now);

}

int dfsAll(int w)
{
    vector<int>time;
    memset(visited,false,sizeof(visited));
    ans.resize(N+1);
    time.resize(N+1);
    for(int i=1;i<=N;i++) if(!visited[i])dfs(i);
    reverse(ans.begin(),ans.end());

    time[ans[0]]=buildTime[ans[0]];
    for(int i=0;i<N;i++)
    {
        int now=ans[i];
        for(int j=i+1;j<N;j++)
            {
                for(auto next:adj[now])
                    if(next==ans[j])
                        time[next]=max(time[next],time[now]+buildTime[next]);
            }
    }

    return time[w];

}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<1001;i++)adj[i].clear();
        cin>>N>>K;
        buildTime.resize(N+1);
        for(int i=1;i<=N;i++) cin>>buildTime[i];
        while(K--)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        int w;
        cin>>w;
        cout<<dfsAll(w)<<"\n";
    }
}
