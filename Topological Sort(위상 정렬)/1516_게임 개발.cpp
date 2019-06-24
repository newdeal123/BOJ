#include<bits/stdc++.h>
using namespace std;
int N;
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

vector<int> dfsAll()
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

    return time;

}


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    buildTime.resize(N+1);
    for(int i=1;i<=N;i++)
    {
        int n;
        cin>>n;
        buildTime[i]=n;
        int tmp;
        while(true)
        {
            cin>>tmp;
            if(tmp==-1) break;
            adj[tmp].push_back(i);
        }
    }
    vector<int> v=dfsAll();
    for(int i=1;i<=N;i++)cout<<v[i]<<"\n";
}
