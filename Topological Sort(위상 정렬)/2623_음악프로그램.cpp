#include<bits/stdc++.h>
using namespace std;
int N,M;
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

vector<int> dfsAll()
{
    memset(visited,false,sizeof(visited));
    ans.resize(N+1);
    for(int i=1;i<=N;i++) if(!visited[i])dfs(i);
    reverse(ans.begin(),ans.end());
    for(int i=ans.size()-1;i>=0;i--)
        for(int j=i-1;j>=0;j--)
            for(auto k:adj[ans[i]])
                if(k==ans[j])return vector<int>();
    return ans;

}


int main()
{
    cin>>N>>M;
    while(M--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=1;i<n;i++) adj[v[i-1]].push_back(v[i]);
    }
    vector<int> v=dfsAll();
    if(!v.size())cout<<0;
    else for(int i=0;i<N;i++)cout<<v[i]<<"\n";
}
