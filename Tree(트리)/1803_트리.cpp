#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
int N,M,cnt;
vector<int>adj[500+2];
bool visited[500+2];

pair<int,int> dfs(int u)
{
    visited[u]=true;
    int nodeCnt=1,adjCnt=adj[u].size();
    for(auto v:adj[u])
        if(!visited[v])
    {
        pair<int,int>tmp=dfs(v);
        nodeCnt+=tmp.first,adjCnt+=tmp.second;
    }
    return {nodeCnt,adjCnt};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    while(true)
    {
        cin>>N>>M;
        if(N+M==0)break;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<500+2;i++)adj[i].clear();
        cnt=0;
        while(M--)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v),adj[v].push_back(u);
        }
        for(int i=1;i<=N;i++)
        {
            if(!visited[i])
            {
                pair<int,int>tmp=dfs(i);
                if(tmp.first-1==tmp.second/2)cnt++;
            }
        }
        cout<<"Case "<<testcase++<<": ";
        if(cnt==0) cout<<"No trees.\n";
        else if(cnt==1)cout<<"There is one tree.\n";
        else cout<<"A forest of "<<cnt<<" trees.\n";
    }

}
