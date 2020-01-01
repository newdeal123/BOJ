#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
int N,arr[11],sum=0,bits=0;
vector<int>adj[11];
bool Union[11],visited[11];

int bfs(int u)
{
    int ret=0;
    queue<int>q;
    visited[u]=true;
    q.push(u);
    ret+=arr[u];
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(auto next:adj[now])
            if(!visited[next]&& Union[now]==Union[next])
            {
                visited[next]=true;
                q.push(next);
                ret+=arr[next];
            }
    }
    return ret;
}
int main()
{
    cin>>N;
    for(int i=1;i<=N;i++){cin>>arr[i],sum+=arr[i];}
    for(int i=1;i<=N;i++)
    {
        int t;
        cin>>t;
        while(t--)
        {
            int tmp;
            cin>>tmp;
            adj[i].push_back(tmp);
        }
    }
    int ans=INF;
    while(bits++<(1<<N))
    {
        memset(visited,0,sizeof(visited));
        memset(Union,0,sizeof(Union));
        int cnt=0,tmp=0;

        for(int i=0;i<N;i++)if(bits&(1<<i))Union[i+1]=true;
        for(int i=1;i<=N;i++)if(!visited[i]){tmp=bfs(i),cnt++;}
        if(cnt==2)ans=min(ans,abs(sum-tmp*2));
    }
    cout<<(ans==INF?-1:ans);
}
