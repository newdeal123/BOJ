#include<bits/stdc++.h>
using namespace std;
int K,N,P;
vector<int>adj[1001],ans;
bool visited[1001];

void dfs(int now)
{
    if(visited[now]) return ;
    visited[now]=true;
    for(auto next:adj[now])
        dfs(next);
    ans.push_back(now);

}

int dfsAll()
{
    vector<int>time;
    memset(visited,false,sizeof(visited));
    ans.resize(N+1);
    time.resize(N+1);
    for(int i=1;i<=N;i++) if(!visited[i])dfs(i);
    reverse(ans.begin(),ans.end());

    vector<pair<int,vector<int>>>Strahler(N+1);
    for(int i=1;i<=N;i++) Strahler[i].first=1;

    for(int i=0;i<N;i++)
    {
        int now=ans[i];
        int len=Strahler[now].second.size();
        sort(Strahler[now].second.begin(),Strahler[now].second.end());
        if(len>=2 && Strahler[now].second[len-1]==Strahler[now].second[len-2])
                Strahler[now].first=Strahler[now].second[len-1]+1;
        else if(len>=1) Strahler[now].first=Strahler[now].second[len-1];

        for(int j=i+1;j<N;j++)
            {
                for(auto next:adj[now])
                    if(next==ans[j])
                        Strahler[next].second.push_back(Strahler[now].first);
            }
    }
    return Strahler[N].first;

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
        cin>>K>>N>>P;
        while(P--)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        cout<<K<<" "<<dfsAll()<<"\n";
    }
}
