#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=1000+2;
int N,M,book[MAX_N],owner[MAX_N];
vector<int> wanted[MAX_N];
bool visited[MAX_N];

bool dfs(int now)
{
    if(visited[now]) return false;
    visited[now]=true;

    for(auto thisBook:wanted[now])
    {
        if(owner[thisBook]==-1 || dfs(owner[thisBook]))
        {
            book[now]=thisBook;
            owner[thisBook]=now;
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N>>M;
        for(int i=0;i<MAX_N;i++)
            wanted[i].clear();
        memset(book,-1,sizeof(book));
        memset(owner,-1,sizeof(owner));
        for(int i=1;i<=M;i++)
        {
            int a,b;
            cin>>a>>b;
            for(int j=a;j<=b;j++)
                wanted[i].push_back(j);
        }
        int sum=0;
        for(int i=1;i<=M;i++)
        {
            memset(visited,0,sizeof(visited));
            if(dfs(i)) sum++;
        }
        cout<<sum<<"\n";
    }
}
